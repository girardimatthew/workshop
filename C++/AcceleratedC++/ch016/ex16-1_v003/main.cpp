// A quine is a computer program which takes no input and produces a copy of its own source code as its only output.

#include<cstdio>
int main(){char n[]=R"(#include<cstdio>
int main(){char n[]=R"(%s%c";printf(n,n,41);})";printf(n,n,41);}