//restore_ip_addresses.cpp

// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]



#include<cstdio>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> to_ret;
        //break ip address into 4 containers aaa.bbb.ccc.ddd
        //a can be from 1-3, b 1-3, c 1-3, d 1-3,
        //regardless these conditions must be satisfied
            //a+b+c+d = s.size()
            // a <= 255, b<=255, c<=255, d<=255
        string aa;
        string bb;
        string cc;
        string dd;
        for(int a=1; a<4; a++){
            for(int b=1;b<4;b++){
                for(int c=1;c<4;c++){
                    for(int d=1; d<4;d++){
                        if(a+b+c+d != s.size()) continue;
                        aa = s.substr(0    ,a); if(aa.size() == 0 || aa.size() > 2 && stoi(aa) > 255) continue;
                        bb = s.substr(a    ,b); if(bb.size() == 0 || bb.size() > 2 && stoi(bb) > 255) continue;
                        cc = s.substr(a+b  ,c); if(cc.size() == 0 || cc.size() > 2 && stoi(cc) > 255) continue;
                        dd = s.substr(a+b+c,d); if(dd.size() == 0 || dd.size() > 2 && stoi(dd) > 255) continue;
                        if(aa[0]=='0' && aa.size() > 1 || bb[0] == '0' && bb.size() > 1 || cc[0] == '0' && cc.size() > 1 || dd[0]                         == '0' && dd.size() > 1 ) {continue;}
                        string to_push = aa + "." + bb + "." + cc + "." + dd;
                        to_ret.push_back(to_push);
                    }
                }
            }
        }
        return to_ret;

    }
};
