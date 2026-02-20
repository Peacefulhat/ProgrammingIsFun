package main

import (
	"fmt"
	"net/http"
)

func Hello(w http.ResponseWriter, req *http.Request){
	fmt.Fprintf(w, "Hello,Sever\n");
}

func main(){
	http.HandleFunc("/hello", Hello);
	http.ListenAndServe(":8090", nil);
}
