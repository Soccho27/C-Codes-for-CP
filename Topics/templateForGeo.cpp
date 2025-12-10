struct Point { double x, y; };
struct V { Point start, endd; };


double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


Point intersection(V u, V v)
{
    Point ret = u.start;
    double t = ((u.start.x - v.start.x) * (v.start.y - v.endd.y) - (u.start.y - v.start.y) * (v.start.x - v.endd.x))
             / ((u.start.x - u.endd.x) * (v.start.y - v.endd.y) - (u.start.y - u.endd.y) * (v.start.x - v.endd.x));
    ret.x += (u.endd.x - u.start.x) * t;
    ret.y += (u.endd.y - u.start.y) * t;
    return ret;
}


void intersection_line_circle(Point c, double r, V Line, Point& p1, Point& p2) {
    Point p = c;
    double t;
    p.x += Line.start.y - Line.endd.y;
    p.y += Line.endd.x - Line.start.x;
    V Line2;
    Line2.start = p;
    Line2.endd = c;
    p = intersection(Line2, Line);
    t = sqrt(r * r - dist(p, c) * dist(p, c)) / dist(Line.start, Line.endd);
    p1.x = p.x + (Line.endd.x - Line.start.x) * t;
    p1.y = p.y + (Line.endd.y - Line.start.y) * t;
    p2.x = p.x - (Line.endd.x - Line.start.x) * t;
    p2.y = p.y - (Line.endd.y - Line.start.y) * t;
}

void intersection_circle_circle(Point c1, double r1, Point c2, double r2, Point& p1, Point& p2) {
    Point u, v;
    double t;
    t = (1 + (r1*r1 - r2*r2) / dist(c1, c2) / dist(c1, c2)) / 2;
    u.x = c1.x + (c2.x - c1.x) * t;
    u.y = c1.y + (c2.y - c1.y) * t;
    v.x = u.x + c1.y - c2.y;
    v.y = u.y - c1.x + c2.x;
    V Line;
    Line.start = u;
    Line.endd = v;
    intersection_line_circle(c1, r1, Line, p1, p2);
}