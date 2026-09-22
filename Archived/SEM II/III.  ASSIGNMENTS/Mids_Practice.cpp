 #include <iostream>
 #include <fstream>
 #include <string>
using namespace std;



class Book{
    private:               //Data Members
    string title ;
    string author ;
    int copies;
    //static member
    static int totalBooks;
                               //Getters
    public:
string getTitle(){
        return title;
}
string getAuthor(){
        return author;
}
int getKopies(){
        return copies;
}
                              //Setters

void setTitle(string title){
    this->title = title;
}
void setAuthor(string author){
    this->author = author;
}
void setKopies(int copies){
    this->copies = copies;
}

string isAvailable() {                //availability function
    if (this->copies > 0) {
        return "Available";
    } else {
        return "Not Available";
    }
}                     
                                                      // Constructor(Default ig)

Book(string title, string author, int copies){    //Parameterized Constructor
    this -> title = title;
    this -> author = author;
    this -> copies = copies;
    totalBooks++;
}

Book(){       //Default Constructor
    this -> title = "Title Not Entered";
    this -> author = "Author X";
    this -> copies = 0;
    totalBooks++;
}

~Book(){              //Destructor
    cout << "The Destructor of The Constructor 'Book' Was Just Called!! "<< endl;
    --totalBooks;
}
static int getTotalBooks(){
    return Book::totalBooks;}
};

int Book ::totalBooks = 7;


class eBook : public Book{
    private:
         //tsk 3
   double fileSize = 2.7;
    public:
    eBook(string title, string author, int copies) : Book(title, author, copies){};     //Constructor for eBook

void displayInfo(){                               //func fo display info

    cout << "\n\nThe Book '" << getTitle() <<  "' Is Written By '" << getAuthor() << ",' With '" << getKopies() << "' Copies in Our Storage, and ";
     cout << "the Book is currently '" << isAvailable() << "'. And the book's size is '" << fileSize << "' GB's" /*Yes, GB's*/ << endl;
}

};


int main(){

    eBook b1("The Alchemist", "Paulo Coelho", 5 );
    b1.displayInfo();  
    
    cout << "\nTotal Books: " << Book::getTotalBooks() <<'\n' << endl;



 return 0; 
}