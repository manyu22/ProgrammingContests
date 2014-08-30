#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
//case insensitive string comparison
bool stringcomp(string a,string b)
{
  if(a.length()!=b.length())return 0;
  else{
    int token =1;
    for(int i=0;i<a.length();i++)    
      if(tolower(a[i])!=tolower(b[i])){
	token=0;
	break;
      }
    return token;
  }
}
int main()
{
  string IN, temp,parse;
  VS kwords,parsein;
  getline( cin, IN );
  int k;
  cin>>k;
  for( int i=0; i < k; i++ ){
    cin>>temp;
    kwords.push_back(temp);
  }
  //parsing 
  for(int i=0; i<IN.length() ; i++){
    int temp=int(IN[i]);
    if(( temp <=90 && temp >=65)||( temp <=122 && temp >=97)){
      parse+=IN[i];
    }
     else if( isspace( IN[i] ) ){
         if(parse.size()!=0){
          parsein.push_back(parse);
          parse.clear();
          }
      //parse+=IN[i];
    }      
  }
  if(parse.size() != 0)
      parsein.push_back(parse);
  
  /*for(int i=0;i<parsein.size();i++){
    cout<<parsein[i]<<endl;
  }*/
  int arr[parsein.size()], label=0;
  memset(arr,-1,sizeof(arr));
  
  for(int i=0 ; i < parsein.size() ; i++ ){
    if(arr[i]==-1){
      arr[i]=label;
      for(int j=i+1; j < parsein.size() ; j++)
	if(stringcomp(parsein[i],parsein[j]))arr[j]=label;
      label++;
    }
  }
  /*for(int i=0;i<parsein.size();i++){
    cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
  }*/
  
  int tofind[label], found[label], flag=0;
  memset(tofind, 0 ,sizeof(tofind));
  memset(found, 0 ,sizeof(found));
  
  int count=0,_k=0;
  for(int i = 0; i < k; i++){
    for(int j=0; j < parsein.size(); j++)
      if( stringcomp( kwords[i], parsein[j] ) ){
	  if( tofind[arr[j]]==0){
	    tofind[arr[j]]=1;
	    _k++;
	  }
	  count+=1;
	  flag=1;
	  break;
      }
      
    if(flag==0)break;
    flag=0;
  }
// cout<<" k = "<<k<<" count = "<< count<<endl;
  if(count!=k)cout<<"NO SUBSEGMENT FOUND"<<endl;
  
  else{
	int left =0, right =0, minL =0 , minR =0, len =0, minLEN =parsein.size()+1;
	
	for(int i=0; i< parsein.size(); i++){
                
	        if( tofind[arr[i]] ){
		  
		  found[arr[i]]+=1;
		  if( found[arr[i]] <= tofind[arr[i]] )
		    len+=1; 
		
		  if( len == _k ){
		      right = i;
		      for(int j = left ; j < right; j++ ){
			
			if( found[ arr[ j ] ] > tofind[ arr[ j ] ] ){
			  left=j;
		          found[ arr[ j ]]-=1;
			}
			else if( tofind[ arr[ j ] ] == 0) continue;
			else {
			  left=j;
			  break;
			}
		      }
		      if( (right - left +1 ) < minLEN ){
			minLEN= right - left +1;
			minL=left; 
			minR=right;
                       
		      }
		  }
		  
		  
		}
	      
	}
	
	if( minLEN <= parsein.size()){
	 // cout<<minL<<"  "<<minR<<endl;
	  for (int j=minL ; j <=minR ;j++){
	    if(parsein[j].size()==0)continue;
	    else if(j<minR)cout<<parsein[j]<<" ";
	    else cout<<parsein[j]<<endl;
	  }
	}
	else cout<<minLEN<<"NO SUBSEGMENT FOUND\n";
  }
  
  
  
  
}
