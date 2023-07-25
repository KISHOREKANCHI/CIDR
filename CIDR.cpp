#include <bits/stdc++.h>
using namespace std;


string complement(string number){
	string nums="";
	for(char i:number){
		if (i=='0'){
			nums+="1";		
		}else{
			nums+="0";
		}
	}
	return nums;
}






string dectobin(int decimal){
    string binary="";
    if(decimal==0){
        binary="0";
    }else{
        while(decimal>0){
            binary=to_string(decimal%2)+binary;
            decimal=decimal/2;
        }
    }
    return binary;
}


int bintodec(string binary){
    int decimal=0;
    int power=0;
    for(int i=binary.size()-1;i>-1;i--){
        int x=binary[i]-'0';
        decimal+=(x)*(pow(2,power));
        power+=1;
    }
    return decimal;
}

vector<string> splitByDelimiter(string ip){
    int n=ip.size();
    vector<string> res;
    string s="";
    for(auto x:ip)
    {
        if(x=='.') 
        {
            res.push_back(s);
            s="";
        }
        else s=s+x;
    }
    res.push_back(s);
    return res;
    
}


int main(){
    map<string,int> iprange;
    string address="192.168.168.188";
    string subnet="255.255.255.192";
    string wildcard="",broadcast="",network="";
    vector<string> temp1=splitByDelimiter(address);
    vector<string> temp2=splitByDelimiter(subnet);
    
    for(int i=0;i<temp1.size();i++){
        iprange[temp1[i]]=255-stoi(temp2[i]);
    }
    
    //Wild card
    wildcard="";
    for(auto x:temp2)
    {
        string comp=complement(dectobin(stoi(x)));
        wildcard+=to_string(bintodec(comp))+'.';
    }
    wildcard.pop_back();
    vector<string>temp3=splitByDelimiter(wildcard);
    
    string end="";
    for(int i=0;i<4;i++)
    {
        end+=to_string(stoi(temp1[i])+stoi(temp3[i]))+".";
    }
    end.pop_back();
    string ans;
    //Network Id
    for(int i=0;i<4;i++){
        int ans1=stoi(temp1[i])&stoi(temp2[i]);
        network+=to_string(ans1)+".";
    }
    network.pop_back();
    
    //Broadcast Ip
    for(int i=0;i<4;i++)
    {
        int ans2=stoi(temp1[i])|stoi(temp3[i]);
        broadcast+=to_string(ans2)+".";
    }
    broadcast.pop_back();
    
    cout<<"IP Address : "<<address<<endl;
    cout<<"subnet mask : "<<subnet<<endl;
    cout<<"start address : "<<address<<endl;
    cout<<"end address : "<<end<<endl;
    cout<<"Wild card : "<<wildcard<<endl;
    cout<<"Network Id : "<<network<<endl;
    cout<<"Broadcast Ip : "<<broadcast<<endl;
    return 0;
    
}
