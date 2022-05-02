class Solution {
public:
    string intToRoman(int num) {
        string ans="";
            if(num>=1000)
            {
                int times=num/1000;
                ans=ans+string(times,'M');
                num-=(times*1000);
            }
            if(num<1000 && num>=500)
            {
                if(num>=900)
                {ans=ans+"CM";
                 num-=900;   
                }
                else
                {ans=ans+'D';
                num-=500;}
            }
            if(num<500 && num>=100)
            {
                if(num>=400)
                {ans=ans+"CD";
                 num-=400;   
                }
                else{
                int times=num/100;
                ans=ans+string(times,'C');
                num-=(times*100);}
            }
            if(num<100 && num>=50)
            {
                if(num>=90)
                {ans=ans+"XC";
                 num-=90;   
                }
                else{
                ans=ans+'L';
                num-=50;}
            }
            if(num<50 && num>=10)
            {
                 if(num>=40)
                {ans=ans+"XL";
                num-=40;   
                }
                else{
                int times=num/10;
                ans=ans+string(times,'X');
                num-=(times*10);}
            }
            if(num<10 && num>=5)
            {
                if(num>=9)
                {ans=ans+"IX";
                 return ans;   
                }
                ans=ans+'V';
                num-=5;
            }
        if(num<5 && num>=1)
            {
                 if(num==4)
                {ans=ans+"IV";
                 return ans;   
                }
                int times=num;
                ans=ans+string(times,'I');
                return  ans;
            }
        return ans;
    }
};