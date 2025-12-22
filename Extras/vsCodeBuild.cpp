{
 "tasks": [
  {
   "type": "process","label": "CP build","command": "bash",
   "args": [
    "-c",
    "ulimit -s262144 -f102400 -t10; g++ -O2 -g -fsanitize=address,undefined -fno-omit-frame-pointer -std=c++17 \"${file}\" -o /tmp/a.out && /usr/bin/time -f \"%esec | %MKB\" /tmp/a.out <in.txt >out.txt"
   ],
   "problemMatcher":
   {
    "owner": "cpbuild", "fileLocation": "absolute",
    "pattern": [
     {
      "regexp": "^(.*):([0-9]+):([0-9]+):\\s+(.*error):\\s+(.*)$",
      "file": 1, "line": 2, "column": 3, "severity": 4, "message": 5
     }]
   },
   "options": {"cwd": "${fileDirname}"},
   "group": {"kind": "build", "isDefault": true},
   "presentation": {"showReuseMessage": false, "clear": true, "revealProblems": "onProblem"}}
 ], "version": "2.0.0"
}