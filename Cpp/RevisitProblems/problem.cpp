 #include"problem.h"

void hello_world(){
  std::cout<<"Hello,World!"<<std::endl;
}

void upper_or_lower_or_numeric(char ch){
  if(ch >= 'a' && ch <='z'){
    std::cout<<"lower_case_character\n";
    return;
  }
  if(ch >= 'A' && ch <='Z'){
    std::cout<<"upper_case_character\n";
    return;
  }
  if(ch >='0' && ch <='9'){
    std::cout<<"numeric_character\n";
  }
  else{
    std::cout<<"special_character\n";
  }
  return;
}


int sum_of_n_natural_numbers(int terms){
  int sum = 0;
  for(int i = 1; i <= terms; ++i){
    sum += i;
  }
  return sum;
}

int sum_of_n_even_numbers(int terms){
  int  sum = 0;
  for(int i = 0; i <= terms; i += 2){
    sum += i;
  }
  return sum;
}

void pattern1(int rows){
  for(int i = 1; i <= rows*rows; ++i){
    if(i%rows==0){
      std::cout<<"*\n";
      continue;
    }
    std::cout<<"* ";
  }
}

void pattern2(int rows){
  for(int i = 1; i <= rows*rows; ++i){
    if(i%rows==0){
      std::cout<<i<<"\n";
      continue;
    }
    std::cout<<i;
  }
}

void pattern3(int rows){
  int width = 1;
  int start = 1;
  for(int i = 1; i<= (rows*rows+rows)/2; ++i){
    if(width==start && width <= rows){
      std::cout<<"*\n";
      width++;
      start=1;
      continue;
    }
    std::cout<<"* ";
    start++;
}
}

void pattern4(int rows){
  int width = 1;
  int start = 1;
  int symbol = 1;
  for(int i = 1; i <= (rows*rows+rows)/2; ++i){
    if(width == start && width <= rows){
      std::cout<<symbol<<"\n";
      width++;
      start = 1;
      symbol++;
      continue;
    }
    std::cout<<symbol<<" ";
    start++;
   }
 }

void pattern5(int rows){

  int start = 1;
  int width = 1;
  int symbol = 1;
  for(int i = 1; i <= (rows*rows+rows)/2; ++i){
    if(width == start && width <= rows){
      std::cout<<symbol<<"\n";
      start = 1;
      width++;
      symbol=1+(width-1);
      continue;
    }
    std::cout<<symbol<<" ";
    start++;
    symbol++;
}
}

void pattern6(int rows){
  
 int start = 1;
  int width = 1;
  int symbol = 1;
  for(int i = 1; i <= (rows*rows+rows)/2; ++i){
    if(width == start && width <= rows){
      std::cout<<symbol<<"\n";
      start = 1;
      width++;
      symbol=1+(width-1);
      continue;
    }
    std::cout<<symbol<<" ";
    start++;
    symbol--;
} 
}

void pattern7(int rows){
  char ch = 'A';
  for(int i = 1; i <= rows*rows; i++){
    if(!(i%rows)){
      std::cout<<ch<<"\n";
      ch=ch+1;
      continue;
    }
    std::cout<<ch<<" ";
  }
}

void pattern8(int rows){
  char ch = 'A';
  for(int i = 1; i <= rows*rows; i++){
    if(!(i%rows)){
      std::cout<<ch<<"\n";
      ch = 'A';
      continue;
    }
    std::cout<<ch<<" ";
    ch=ch+1;
  }
}  

void pattern9(int rows){
  int start = 1;
  int width = 1;
  char symbol = (char)(65+rows-1);
 for(int i = 1; i <= (rows*rows+rows)/2; ++i)
   {
    if(width == start && width <= rows){
      std::cout<<symbol<<"\n";
      start = 1;
      symbol=symbol-width;
      width++;
      continue;
    }
    std::cout<<symbol<<" ";
    start++;
    symbol++;
}
}

void pattern10(int rows){
  int tstar = 1;
  int space = 1;
  for(int i = 1; i <= rows*rows; i++)
  {
    if(!(i%rows)){
      std::cout<<"*\n";
      tstar++;
      space = 1;
      continue;
    }
      if(space<=rows-tstar){
	std::cout<<" ";
      }else{
	std::cout<<"*";
      }
      space++;
  }
}

void pattern11(int rows){
  int star = 1;
  int tstars = rows;
  for(int i = 1; i<=(rows*rows+rows)/2; i++){   
    if(star>=tstars){
      std::cout<<"*\n";
      tstars--;
      star=1;
      continue;
    }
      if(star<=tstars){
      std::cout<<"*";
    }
    star++;
 }
}

void pattern12(int rows){

  int space=0;
  int tspace=0;
  for(int i=1; i<=rows*rows; i++){
    if(!(i%rows)){
      std::cout<<"*\n";
      space++;
      tspace=0;
      continue;
    }
    if(tspace<space){
      std::cout<<" ";
    }else{
      std::cout<<"*";
    }
    tspace++;
  }
}

void pattern13(int rows){
  int tspace=1;
  int space=rows;
  int w=0;
  int total_stars =((rows * rows) + ((rows-1)*(rows-1) + (rows-1))/2);

  for(int i=1 ; i <= total_stars; i++){
    
    if(!(tspace%(rows+w))&&w<rows){
        std::cout<<"*\n";
     	space--;
	tspace=1;
	w++;
	continue;
    }
    
    if(tspace<space){
	std::cout<<" ";
      }
      else{
	std::cout<<"*";
      }
      tspace++;
  }
}


void pattern14(int rows){
  //TODO: for reference check 2nd last program of pattern in notes.
}


void pattern15(int rows){
  //TODO: for refernce check last program of pattern in notes.
}

void fib(int terms){
  int first=0;
  int second=1;
  long long int sum=first+second;
  std::cout<<first<<","<<second<<",";
  for(int i = 1; i <= terms-1; i++){
    std::cout<<sum<<",";
    first=second;
    second=sum;
    sum=first+second;
  }
  std::cout<<sum;
}


void product_sum_of_digits(int number){
  int sum=0;
  int product=1;
  while(number!=0){
    product*=number%10;
    sum+=number%10;
    number/=10;
  }
  std::cout<<"Sum: "<<sum<<","<<"Product: "<<product;
}

int reverse(int number){// leetcode
  // if ending numbers are zeros its will, not be visible.
  int reverse=0;
 
  while(number!=0){
    if(reverse<INT_MIN/10||reverse>INT_MAX/10){return 0;}
    reverse=reverse*10+(number%10);
    number/=10;
}
  return reverse;
}

int bit_count(int number){
  unsigned int bits=0;
  while(number){
    if(number&1){
      bits++;
    }
    number>>=1;
  }
  return bits;
}


int complement_of_number(int number){ // leetcode
  int mask=0;
  int temp=number;
  while(temp!=0){
    mask=(mask<<1)|1;
    temp=temp>>1;
  }
  return ~number&mask;
}

int two_complement_of_negative_number(int number){
  //TODO
  return 0;
}

int total_number_of_notes(int money){
  //TODO
  return 0;
}

void ap_series(int seed){
  for(int i=1; i<=seed; ++i){
    std::cout<< 3*i+7<<" ";
  }
}

int count_setbits(int first, int second) {
    int total = 0;
    while (first != 0 || second != 0) {
        if (first & 1) {
            total++;
        }
        if (second & 1) {
            total++;
        }
        first = first >> 1;
        second = second >> 1;
    }
    return total;
}


int factorial(int number){
  if(number==0){
    return 1;
  }
  int fact=1;
  for(int i=1;i<=number; ++i){
    fact=fact*i;
  }
  return fact;
}

int sum_of_array_elements(int *arr,int size){
  int sum=0;
  for(int i=0; i<size;i++){
    sum+=arr[i];
  }
  return sum;
}


bool linear_search(int *arr, int size, int el){
  int found=0;
  for(int i=0;i<size; ++i){
    if(arr[i]==el){
      found = 1;
      break;
    }
  }
  return found;
}

int find_unique_element(int *arr, int size){ // codestudio.
  // once element occurs once but other appear twice.
  int ans=0;
  for(int i=0;i<size;i++){
    ans=ans^arr[i];
  }
  return ans;
}

void swap_alternate(int *arr, int size){
  for(int i=0;i<size-1;i+=2){
    int temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
  }
  std::cout<<"\n";
}



int find_duplicate(int *arr, int size){
  int ans=0;
  for(int i=0;i<size;i++){
    ans=ans^arr[i];
  }

  for(int i=0;i<size-1;i++){
    ans=ans^arr[i];
  }
  return ans;
}

bool unique_occurrences(int *arr, int size){
  //leetcode. optimized solution use hashtable.
  // example test cases working but not submited because of
  // time complexity.
  // for now bruteforce becuse currently i don't know hash table.
  std::pair<int, int> store[MAX];
  for(int i=0;i<MAX;i++){
    store[i].first=0;
    store[i].second=0;
  }
  int e=0;
  for(int i=0; i<size; i++){
    if(arr[i]==-1001){continue;}
    for(int j=i;j<size; j++){
      if(arr[i]==arr[j+1]){
	  store[e].first=arr[i];
	  store[e].second++;
	  arr[j+1]=-1001;
	}
    }
      e++;
  }
    bool flag=1;
    for(int i=0;i<e;i++){
      
      for(int j=i;j<e-1;j++){
	if(store[i].second==store[j+1].second){
	  flag=0;
	  return flag;
	}
      }
    }
  return flag;
}

void print(int *arr, int size){
  std::cout<<"Array: {";
  for(int i=0;i<size-1;i++){
    std::cout<<arr[i]<<",";
  }
  std::cout<<arr[size-1]<<"}";
}


void find_all_duplicates(int *arr, int size){
  //leetcode.
  // not exactly correct solution. brute force solution.
  std::pair<int,bool>cont[MAX];
  int e=0;
  for(int i=0;i<size;i++){
    if(arr[i]==-1){continue;}
    for(int j=i;j<size-1;j++){
      if(arr[i]==arr[j+1]){
	cont[e].first=arr[i];
	cont[e].second=true;
	e++;
	arr[j+1]=-1;
      }
    }
  }

  for(int i=0;i<e;i++){
    std::cout<<cont[i].first;
    std::cout<<cont[i].second;
    std::cout<<"\n";
  }
}


/*void intersection_of_arrays(int *arr,int size,int *arr2,int size2){// not set , but arrays, if repeation is allowed
  int intersection[MAX]={0};
  int e=0;
  bool flag=0;
  for(int i=0;i<size2;i++){
    	for(int k=0;k<e;k++){
	  if(intersection[k]==arr2[i]){
	    //std::cout<<"check";
	    flag=1;
	    break;
	  }
	}
	if(flag==1){flag=0;continue;}
    for(int j=0;j<size;j++){
      if(arr[j]==arr2[i]){
	intersection[e]=arr2[i];
	e++;
	break;
      }
    }
  }
  
    for(int i=0;i<e;i++){
      std::cout<<arr2[i]<<":";
      std::cout<<intersection[i];
      std::cout<<"\n";
    }
}

*/

/*void intersection_of_arrays(int *arr,int size,int *arr2,int size2){
  // if sets
  int intersection[MAX]={0};
  int e=0;
  for(int i=0;i<size2;i++){
    for(int j=0;j<size;j++){
      if(arr2[i]==arr[j]){
	intersection[e]=j;
	e++;
	break;
      }
    }
  }

  for(int i=0;i<e;i++){
    std::cout<<arr2[i]<<":";
    std::cout<<intersection[i]<<"\n";
  }
  
}
*/

void intersection_of_arrays(int *arr,int size,int *arr2,int size2){
  //2pointer approach;
  int intersection[MAX];
  int i=0,j=0,e=0;
  while(i<size&&j<size2){
    
    if(arr[i]==arr2[j]){
      intersection[e]=i;
      i++;
      j++;
      e++;
    }

    if(arr[i]<arr2[j]){
      i++;
    }
    if(arr[i]>arr2[j]){
      j++;
    }
  }
  for(int i=0;i<e;i++){
    std::cout<<arr2[i]<<",";
    std::cout<<intersection[i]<<"\n";
  }
}

void pair_sum(int *arr,int size,int sum){
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
      if(arr[i]+arr[j]==sum){
      std::cout<<arr[i]<<":"<<arr[j]<<"\n";
      break;
      }
    }
  } 
}
  
void sort01(int *arr, int size){
  int i=0,j=size-1;
  while(i<j){
    if(arr[j]==0&&arr[i]==1){
      int temp=arr[j];
      arr[j]=arr[i];
      arr[i]=temp;
	  i++;
	  j--;
	  continue;
	}
    
    if(arr[i]==0){
      i++;
    }    
    if(arr[j]==1){
      j--;
    }

  }
}

void sort012(int *arr,int size){
  int i=0,k=size-1;
  int j=0,
  while(i<=k){
   
  }
}
