import std.stdio;
int main(){
 
  writeln("int.sizeof:: ",int.sizeof);
  writeln("double.sizeof:: ",double.sizeof);
  int h=23;
  string str="Hello,Strings";
  writeln(str);
  for(int i=0;i<str.sizeof-1;++i){
    writeln(str[i]);
    writeln("\n");
  }
  
  return 0;
}
