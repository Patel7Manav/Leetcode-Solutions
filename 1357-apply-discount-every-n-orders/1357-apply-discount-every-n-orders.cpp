class Cashier {
public:
    int cust,disc,num=1;
    map<int,int>mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        
        for(int i=0;i<products.size();i++)
        {
            mp[products[i]]=prices[i];
        }
        cust=n,disc=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double val=0;
        for(int i=0;i<product.size();i++)
        {
            val+=(mp[product[i]]*amount[i]);
        }
        if(num%cust==0)
        {
            double discval=(100-disc);
            discval/=100;
            val=val*discval;
        }
        num++;
        return val;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */