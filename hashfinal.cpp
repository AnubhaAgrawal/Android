#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 10;
 class HashNode
{
    public:
    int key;
	int value;
	HashNode* next;
        HashNode(int key, int value)
        {
            this->key = key;
	    this->value = value;
	    this->next = NULL;
        }
        HashNode()
        {}
};
class HashMap:public HashNode
{
private:
        HashNode **table;
    public:
        HashMap()
        {
            table = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                table[i] = NULL;
        }
        ~HashMap()
        {
            for (int i = 0; i < TABLE_SIZE; ++i)
	    {
                HashNode* entry = table[i];
                while (entry != NULL)
	        {
                    HashNode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] table;
        }
        /*
         * Hash Function
         */
       int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
 
     void Insert(int value);
     void Remove(int key);
     int Search(int key,int value);
     void displayc();
     void insertl(int value);
     void insertq(int value);
     void insertd(int value);
     void delete1(int key);
     void search1(int key,int value);
     void display();
    // void searchvl(int value);
public:
    int key,f;
	int value;
    int i, htable[TABLE_SIZE];
    void Hash1()
     {
      i=0;
      for (int i = 0; i <TABLE_SIZE ; i++)
        {
       htable[i]=0;
         }
      }
         int hash(int value)
            {
           return(value%TABLE_SIZE);
              }
              
           int hash2(int value)
              {
            return (7-value%7);
                }
   
};
        void HashMap::Insert(int value)
        {
            int hash_val = hash(value);
            key = hash_val;
            HashNode* prev = NULL;
            HashNode* entry = table[hash_val];
            while (entry != NULL)
            {
                prev = entry;
                entry = entry->next;
            }
            if (entry == NULL)
            {
                entry = new HashNode(key, value);
                if (prev == NULL)
	        {
                    table[hash_val] = entry;
                }
	        else
	        {
                    prev->next = entry;
                }
            }
            else
            {
                entry->value = value;
            }
        }
        
        void HashMap::Remove(int key)
        {
            int hash_val = HashFunc(key);
            HashNode* entry = table[hash_val];
            HashNode* prev = NULL;
            if (entry == NULL || entry->key != key)
            {
            	cout<<"No Element found at key "<<key<<endl;
                return;
            }
            while (entry->next != NULL)
	    {
                prev = entry;
                entry = entry->next;
            }
            if (prev != NULL)
            {
                prev->next = entry->next;
            }
            delete entry;
            cout<<"Element Deleted"<<endl;
        }
        
        int HashMap::Search(int key,int value)
        {
            bool flag = false;
            int hash_val = HashFunc(key);
            HashNode* entry = table[hash_val];
            while (entry != NULL)
	    {
                if (entry->key == key)
	        {
                    //cout<<entry->value<<" ";
                    if(entry->value == value)
                    {
                    cout<<"Element is present at given key";
                        flag = true;
                        
                }}
                entry = entry->next;
            }
            if (!flag)
                return -1;
        }
  void HashMap::displayc()
  {
  //int hash_val = HashFunc(key);
   for (int i = 0; i <TABLE_SIZE ; i++)
    {
            HashNode* entry = table[i];
            cout<<"\nElement at key "<<i<<" : ";
             while (entry != NULL)
	    {
                //if (entry->key == key)
	        {
                    cout<<entry->value<<" ";
                   
                }
                entry = entry->next;
            }
   }
   }


void HashMap::insertl(int value)
{

int h = hash(value);
if(hash(value)!=9)
{f=0;
}

if(f==1)
{
h=0;
f=0;
}

while(htable[h+i])
{
if(f==1)
{
h=0;
f=0;
}
if(hash(value)+i==9)
{f=1;
}
i++;
}
key = hash(h+i);
cout<<i<<endl;
cout<<key<<endl;
htable[key]=value;
if(hash(value)+i==9)
{f=1;
}

}

void HashMap::insertq(int value)
{

int h = hash(value);
if(hash(value)!=9)
{f=0;
}

if(f==1)
{
h=0;
f=0;
}

while(htable[h+i])
{
if(f==1)
{
h=0;
f=0;
}
if(hash(value)+i*i==9)
{f=1;
}
i++;
}
key = hash(h+i*i);
//cout<<i<<endl;
//cout<<key<<endl;
htable[key]=value;
if(hash(value)+i*i==9)
{f=1;
}

}
void HashMap::insertd(int value)
{
while(htable[hash(value)+i])
{i++;
}
key = hash(hash(value)+hash2(value)*i);
//cout<<i<<endl;
//cout<<key<<endl;
htable[key]=value;


}


void HashMap::delete1(int key)
{
if(htable[key-1])
htable[key-1]=0;
else
cout<<"No element is present at this key";

}

void HashMap::search1(int key, int value)
{
if(htable[key]==value)
{cout<<"Element is present at given key ";
}
else
{cout<<"this element is not present at given key";
}
}



void HashMap::display()
{
    for (int i = 0; i <TABLE_SIZE ; i++)
    {
        
        if (!htable[i])
            cout<<"Position: "<<i <<" Element: Null"<<endl;
        else
            cout<<"Position: "<<i <<" Element: "<<htable[i]<<endl;
    }
 
}



int main()
{
   
    int key, value;
    int choice,choice1,flag=0;
    
    while (1)
    {flag=0;
     HashMap hash;
     hash.Hash1();
        cout<<"Operations on Hash Table by \n Press 1. linear probing \n Press 2. quadratic probing \n Press 3. chaining \n Press 4. Double Hashing \n press 5. Exit :"<<endl;
        cin>>choice1;
        hash.f=0;
        switch(choice1)
        {
        case 1:
    while(1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete element at a key"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        hash.i=0;
        
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
           
            hash.insertl(value);
            break;
        case 2:
             cout<<"Enter key of the element to be searched: ";
            cin>>key;
           cout<<"Enter element to be searched: ";
            cin>>value;
           
             hash.search1(key,value);
            break;
        case 3:
           // cout<<"Enter key of the element to be deleted: ";
            //cin>>key;
            hash.display();
            break;
         case 4:
           cout<<"Enter key of the element to be deleted: ";
           cin>>key;
            hash.delete1(key);
            break;  
            
        case 5:
             flag =1;
            break;
        default:
           cout<<"\nEnter correct option\n";
       }
       if(flag==1){
        break;
        }
}
       
       break;
       
       
   case 2:
    while(1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete element at a key"<<endl;
       
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
           
            hash.insertq(value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
           cout<<"Enter element to be inserted: ";
            cin>>value;
           
             hash.search1(key,value);
            break;
        case 3:
           // cout<<"Enter key of the element to be deleted: ";
            //cin>>key;
            hash.display();
            break;
         case 4:
           cout<<"Enter key of the element to be deleted: ";
           cin>>key;
            hash.delete1(key);
            break;  
          
        case 5:
             flag =1;
            break;
        default:
           cout<<"\nEnter correct option\n";
       }
       if(flag==1){
        break;
        }
}
       
    break;
    case 3:
    while(1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete element at a key"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
             cout<<"Enter element to be inserted: ";
            cin>>value;
            
            hash.Insert(value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            cout<<"Enter element to be searched: ";
            cin>>value;
            //cout<<"Element at key "<<key<<" : ";
            if (hash.Search(key,value) == -1)
            {
	        cout<<"No element found at key "<<key<<endl;
	        continue;
	    }
            break;
        case 3:
           // cout<<"Enter key of the element to be deleted: ";
            //cin>>key;
            hash.displayc();
            break;
         case 4:
           cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 5:
             flag =1;
            break;
        default:
           cout<<"\nEnter correct option\n";
       }
       if(flag==1){
        break;
        }
}
       
    break;
    
    case 4:
    while(1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete element at a key"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        hash.i=0;
        
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
           
          
            hash.insertd(value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
           cout<<"Enter element to be searched: ";
            cin>>value;
           
             hash.search1(key,value);
            
            break;
        case 3:
           // cout<<"Enter key of the element to be deleted: ";
            //cin>>key;
            hash.display();
            break;
         case 4:
           cout<<"Enter key of the element to be deleted: ";
           cin>>key;
            hash.delete1(key);
            break;    
        case 5:
             flag =1;
            break;
        default:
           cout<<"\nEnter correct option\n";
       }
       if(flag==1){
        break;
        }
}
       
       break;
    
    case 5:
      exit(0);
    default:
        cout<<"\nEnter correct option\n";
       
    }
    
}
    return 0;
}
