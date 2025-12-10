// LCS
// https://www.youtube.com/watch?v=__Cu92rei1s&list=PL-Jc9J83PIiEoZSwjEZT3TvpKG16FntFL&index=2
// from Pepcoding

void genLPS(){
    vector<int> lps(n,0);
    int i=1,len=0;
    // here i=1 because we want only the proper suffix
    while(i<s.size()){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len>0)len=lps[len-1];
            else i++;
        }
    }
}