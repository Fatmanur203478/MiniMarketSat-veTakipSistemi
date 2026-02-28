#include <iostream>
using namespace std;

int main ()
{
string productName[10];
float price[10];
int stock [10];
int productCount =0;
int choice ;

double dailyRevenue = 0.0; // daily revenue
do{
    cout<<"\n--- MINI MARKET---\n";
    cout<< "1 - add product\n";
    cout<<"2- list products \n";
    cout<<"3-make a sale\n";
    cout<<"4- low stock ıtems & out of stock products\n";
    cout<<"5- show daily revenue\n";
    cout<<"6- close day (reset revenue)\n";
    cout<<"0- exit\n";
    cout<<"choice:";
    cin>>choice;

if (cin.fail()) {
    cin.clear(); // hatayı temizle
    cin.ignore(10000, '\n'); // satırı çöpe at
    cout << "Please enter a NUMBER (0-6).\n";
    continue; // menüye geri dön
}
cout << "DEBUG choice=" << choice << endl;








    switch (choice){
        case 1:
        if(productCount>=10){
            cout<<"the product limit reached!\n";
            break;
        }
cout<<"productName:";
cin>>productName[productCount];
cout<<"price:";
cin>> price[productCount];
cout<<"stock:";
cin>>stock[productCount];

productCount++;
break;

case 2:
if (productCount == 0){
    cout<<"No products avaliable.\n";
    break;
}
for(int i =0; i< productCount; i++){
    cout<<i+1<<")"<<productName[i]<<" | price:"<<price[i]<<" | stock:"<<stock[i]<<endl;
}
break;
case 3:{
    int no, quantity;
    cout<<"Product number:";
    cin>>no;
    if(no<1 || no> productCount){
        cout<<"Invalid product!\n";
        break;
    }
    cout<<"sale quantity:";
    cin>>quantity;
    if(quantity<=0){
        cout<<"Invalid quantity!\n";
        break;
    }
    if(stock[no -1]< quantity){
        cout<<"Insufficient stock!\n";
    }else{
        stock[no -1]-= quantity;
        double total=price[no-1]*quantity;
        dailyRevenue+= total;

        cout<<"sale complated. Total amount:"<<total<<"TL\n";
    }
    break;
}
case 4: {
    bool found = false;
    cout<<"\n---LOW STOCK PRODUCTS(<=5)---\n";
    for(int i = 0; i< productCount; i++){
        if(stock[i]> 0 && stock[i]<=5){
            cout<<productName[i]<<"low stock!(" << stock[i]<<")\n";
            found =true;
        }
    }
    if(!found)
    cout<<"no low stock products.\n";

    bool outOfStock = false;
    cout<<"\n---OUT OF STOCK PRODUCTS---\n";
    for(int i = 0; i< productCount;i++){
        if (stock[i]==0){
            cout<<productName[i]<<"(stock : 0)\n";
            outOfStock = true;
        }
    }
    if(!outOfStock)
    cout<<"no out of stock products.\n";
    break;
}
case 5:
cout<<"Daily Revenue:"<<dailyRevenue<<"TL\n";
break;

case 6:{
    char confirm;
    cout<<"Do you want to close the day? (Y/N):";
    cin>>confirm;

    if(confirm== 'Y' ||  confirm=='y'){
        cout<<"\n---DAY CLOSİNG---\n";
        cout<<"Daily Revenue:"<<dailyRevenue<<"TL\n";

        //AUTOMATİCALLY SHOW OUT OF STOCK PRODUCTS
        bool outOfStock = false;
        cout<<"\n---OUT OF STOCK PRODUCTS---\n";
        for(int i = 0; i<productCount; i++){
            if(stock[i]== 0){
                cout<<productName[i]<<"(stock:0)\n";
                outOfStock=true;
            }
        }
        if(!outOfStock)
        cout<<"No out of stock products.\n";

        dailyRevenue=0.0;  //reset revenue
        cout<<"\nRevenue reset. New day started.\n";
    }else{
        cout<<"Operation cancelled.\n";
    }
    break;
}
case 0:
cout<<"Program is closing...\n";
break;
default:
cout<<"Invalid choice!\n";
    }




}while (choice!=0);

return 0;

}