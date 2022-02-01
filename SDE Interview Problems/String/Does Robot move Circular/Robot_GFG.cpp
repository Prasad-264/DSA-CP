#include <iostream>
#include <string>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--) {
	    
	    string str;
	    cin>>str;
	    
	    int x = 0 , y = 0;
	    char direction = 'N';
	    
	    for(int i=0 ; i<str.size() ; i++) {
	        if(str[i] == 'G') {
	            if(direction == 'N') {
	                y++;
	            }
	            else if(direction == 'S') {
	                y--;
	            }
	            else if(direction == 'E') {
	                x++;
	            }
	            else if(direction == 'W') {
	                x--;
	            }
	        }
	        else if(str[i] == 'R') {
	            if(direction == 'N') {
	                direction = 'E';
	            }
	            else if(direction == 'S') {
	                direction = 'W';
	            }
	            else if(direction == 'E') {
	                direction = 'S';
	            }
	            else if(direction == 'W') {
	                direction = 'N';
	            }
	        }
	        else if(str[i] == 'L') {
	            if(direction == 'N') {
	                direction = 'W';
	            }
	            else if(direction == 'S') {
	                direction = 'E';
	            }
	            else if(direction == 'E') {
	                direction = 'N';
	            }
	            else if(direction == 'W') {
	                direction = 'S';
	            }
	        } 
	    }
	    if(x == 0 && y == 0) {
	        cout<<"Circular"<<endl;
	    }
	    else {
	        cout<<"Not Circular"<<endl;
	    }
	}
	
	return 0;
}