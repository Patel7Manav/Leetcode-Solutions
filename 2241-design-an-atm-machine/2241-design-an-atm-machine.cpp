class ATM {
public:
    vector<long long>total;
    ATM() {
        total.resize(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
	
        for(int i=0;i<5;++i){
         total[i]+=(long long)banknotesCount[i];
        }
    } 
    
    vector<int> withdraw(int amount) {
        vector<int>ans;
        ans.resize(5,0);
		
        for(int i=4;i>=0;--i)
        {
          if(i==4)
          {
            int num=amount/500;
            num=min((long long)num,total[i]);
            amount-=num*500;
            ans[i]=num;
          }
          else if(i==3)
          {
            int num=amount/200;
            num=min((long long)num,total[i]);
            amount-=num*200;
            ans[i]=num;
          }
          else if(i==2)
          {
            int num=amount/100;
            num=min((long long)num,total[i]);
            amount-=num*100;
            ans[i]=num;
             
          }
          else if(i==1)
          {
            int num=amount/50;
            num=min((long long)num,total[i]);
            amount-=num*50;
            ans[i]=num;
          }
          else if(i==0)
          {
            int num=amount/20;
            num=min((long long)num,total[i]);
            amount-=num*20;
            ans[i]=num;
          }
        }
		
         if(amount==0)
         {
           for(int i=0;i<5;++i)
           {
             total[i]-=(long long)ans[i];
             
           }
           return ans;
         }
		 //else simply return [-1]
         return {-1};
    }
};