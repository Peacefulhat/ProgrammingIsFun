import std.stdio;
import std.process;

void main(){
  auto dmdPid=spawnProcess(["dmd","hello.d"]);
}
