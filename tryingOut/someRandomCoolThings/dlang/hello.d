import std.stdio;
int main(){
 
  writeln("int.sizeof:: ",int.sizeof);
  writeln("double.sizeof:: ",double.sizeof);
  int h=23;
  string str="Hello,Strings";
  writeln(str);
  foreach(i;str){
    writeln(i);
  }
  
  return 0;
}
