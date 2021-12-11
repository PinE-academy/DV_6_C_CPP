#include <iostream>
#include <map>
#include <cstring>
#include <list>

//Using item class to make a list of items 
class item{

    public:
    std::map<std::string, double> item_inf;
    
    public:
    item(){};
    ~item(){};

    void add_item(std::string name, double amount){   //For adding the items in item list
    
    item_inf[name]=amount;

    }

     void show_item()                    //To display the Item list
    {

    int i=1;
    auto beg = item_inf.begin();
    auto end = item_inf.end();

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }
};

//Using inheritance to use the object of the keys used in map
class Bucket : public item {
    
    public:
    std::map<std::string,int> Bucket_item;
    

    public:
    Bucket(){};
    ~Bucket(){};

    void add_item_in_bucket(std::string name,int quantity=1)     //For adding the items in bucket list
    {
        Bucket_item[name]=quantity;
    }

    void bill(){                                //Generating the bill by comparing keys
        double sum=0;
        int i=1;
        auto beg = item_inf.begin();
        auto end = item_inf.end();
        auto beg_bucket= Bucket_item.begin();
        auto end_bucket= Bucket_item.end();
        
        while (beg_bucket!=end_bucket)
        {
            auto it=item_inf.find(beg_bucket->first); //Using the find() to match the key in two maps
            if(it!=end){
                sum=sum+(it->second*beg_bucket->second);
                std::cout << i << '.' << '\t' << beg_bucket->first << '\t' << (it->second*beg_bucket->second) << '\n';
                i++;
            }

            else    
                std::cout << "->>>>> " << beg_bucket->first << " is not in the Item list!" << '\n';
                
            beg_bucket++;
        }

        std::cout <<'\n' <<  "Total Amount = " << sum << std::endl; 
    }

    void show_item_in_bucket()           //To display the items in bucket list
    {

    int i=1;
    auto beg = Bucket_item.begin();
    auto end = Bucket_item.end();

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }

};

int main() {

    std::string a[]={"Apple","Orange","Banana"}; //string for adding item in item list
    std::string e[]={"Orange", "Banana" };  //string for adding item in bucket list
    int d[]={2,3};                  //Quantity array
    double b[]={10000,20000,300}; //Amount array
    
    //Object of bucket class
    Bucket cart;
    
    //For transerving in the array
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(e)/sizeof(e[0]);
     
    for(int i=0; i<m; i++)         //Adding items in the item list
    {
        cart.add_item(a[i],b[i]);      
    }

    std::cout << "------ List of items ------" << '\n' ; 
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' << std::endl;
    //To show the items in item list
    cart.show_item(); 


    //Adding a net item
    cart.add_item("Grapes", 1000);
     std::cout <<'\n' << "-> Adding New items" << '\n' ;
     std::cout << '\n' <<"------ List of items ------" << '\n';
     std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' <<  std::endl;

    cart.show_item();

    for(int i=0; i<n; i++)       //Adding item in bucket list with their respective quantiy
    {
        cart.add_item_in_bucket(e[i],d[i]);      

    }

    std::cout <<'\n' << "-> Adding items in bucket" << '\n' ;
    std::cout << '\n' <<"------ List of items in bucket ------" << '\n';
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Quantity" << '\n' <<  std::endl;

    cart.show_item_in_bucket(); //Showing the items with quantity in bucket

    std::cout << '\n' <<"------ Final Bill ------" << '\n';
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' <<  std::endl;


    cart.bill();  //Generating the final bill of cart

}