#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// List of all the classes.
class Page;
class User;
class Post;
class Comment;
class Facebook;
class Activity;
class Object;
class Helper;

// Helper class that contains the helping functions
class Helper 
{
public:

	//Function to calculate the length of string.
	static int StringLength(char* str) 
	{
		int Length = 0;
		for (char* temp = str; *temp != '\0'; temp++)
		{
			Length++;
		}
		return Length;
	}

	//Function GetStringFromBuffer
	static char* GetStringFromBuffer(char* buffer) 
	{
		int strlen = StringLength(buffer);
		char* str = 0;

		if (strlen > 0)
		{
			str = new char[strlen + 1];
			char* tempdest = str;

			for (char* tempsrc = buffer; *tempsrc != '\0'; )
			{
				*tempdest++ = *tempsrc++;
			}
			*tempdest = '\0';
		}
		return str;
	}

	// Function to check that the two functions are equal or not
	static bool isEqual(char* arr1, const char* arr2)
	{
		int i = 0;
		while (arr2[i] != '\0')
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}
	static char* int_to_char(int num) {
		int count = 0;
		int n = num, inc = 10;

		while (n != 0) {
			n /= 10;
			count += 1;

		}
		char* arr = new char[count + 1];
		int i;
		for (i = count - 1; i >= 0; i--) {
			arr[i] = (num % inc) + '0';
			num /= 10;
		}
		arr[count] = '\0';
		return arr;
	}

	//Function to concatenate two strings
	static char* Concatenate(char* str1, char* str2) 
	{
		int i, j = 0;
		for (i = 0; str1[i] != '\0'; i++)
		{
			j++;
		}
			
		for (i = 0; str2[i] != '\0'; i++) 
		{
			str1[j] = str2[i];
			j++;
		}
		str1[j] = '\0';
		str1 = Helper::GetStringFromBuffer(str1);
		return str1;
	}
};

//Date wali class
class Date
{
private:
	int day;
	int month;
	int year;
	static Date CurrentDate;

public:

	//constructor of date class.
	Date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}

	// destructor
	~Date()
	{

	}


	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}

	//Function to print date
	void PrintDate()
	{
		cout << "(" << day << "/ " << month << "/ " << year << ")" << endl;
	}

	//Function to set the date
	void SetDate(int D, int M, int Y)
	{
		day = D;
		month = M;
		year = Y;
	}

	//function to set the current date
	static void SetCurrentDate(int D, int M, int Y)
	{
		CurrentDate.day = D;
		CurrentDate.month = M;
		CurrentDate.year = Y;
	}

	//Function to return the current date
	static Date GetCurrentDate()
	{
		return CurrentDate;
	}

	//Operator of equal to check  that the dates are equal or not
	bool operator==(Date rhs)
	{
		if (day == rhs.day && month == rhs.month && year == rhs.year)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//Function to read date from the file
	void ReadDateFromFile(ifstream& fin)
	{
		fin >> day;
		fin >> month;
		fin >> year;
	}

};
Date Date::CurrentDate;

// Object class
class Object
{
private:
	char* Id;

public:

	// Constructor of object class
	Object() 
	{
		Id = NULL;
	}
	
	// Destructor of object class
	~Object() 
	{
		if (Id != NULL) 
		{
			delete[] Id;
		}
	}

	// Function to get ID
	char* GetID()
	{
		return Id;
	}

	//Function that sets the id.
	void SetId(char* ID)
	{
		Id = Helper::GetStringFromBuffer(ID);
	}

	//The list of virtual functions
	virtual void AddPostToTimeline(Post* PTR) {};
	virtual void printName() {}
	virtual void PrintNameOnly() {};
	virtual void SetPost(Post*&) {};
	
};

// Activity ki class
class Activity
{
private:
	int Type;
	char* Value;

public:

	//Constructor of activity class
	Activity() 
	{
		Type = 0;
		Value = NULL;
	}

	//Function to read activity from file
	void ReadActivityFromFile(ifstream& fin)
	{
		char temp[100];
		fin >> Type;
		fin.getline(temp, 100);
		Value = Helper::GetStringFromBuffer(temp);
	}

	//Function for printing the activity
	void ActivityPrint()
	{
		{
			switch (Type)
			{
			case 1:
				cout << " is Feeling " << Value << endl;
				break;
			case 2:
				cout << " is Thinking About " << Value << endl;
				break;
			case 3:
				cout << " is Making " << Value << endl;
				break;
			case 4:
				cout << " is Celebrating " << Value << endl;
				break;
			default:
				cout << "Not valid , try again!" << endl;
				break;
			}
		}
	}

	//Destructor
	~Activity()
	{
		if (Value)
		{
			delete  Value;
		}
	}
};

//Comment wali class
class Comment
{
private:
	char* CommmentID;
	char* Message;
	Object* CommmentedBy;

public:

	//constructor
	Comment() 
	{
		CommmentID = NULL;
		Message = NULL;
		CommmentedBy = NULL;
	}

	//destructor
	~Comment() 
	{
		if (CommmentID)
		{
			delete[] CommmentID;
		}
		if (Message)
		{
			delete[] Message;
		}	
	}

	//Function to get the id
	char* GetID()
	{
		return CommmentID;
	}

	//Function to get the text
	char* GetText()
	{
		return Message;
	}

	//Function to get the comment by
	Object* GetCommentBy()
	{
		return CommmentedBy;
	}

	//Function to set the id
	void SetID(char* Id)
	{
		CommmentID = Helper::GetStringFromBuffer(Id);
	}

	//Function to set the text
	void SetText(char* msg) 
	{
		Message = Helper::GetStringFromBuffer(msg);
	}
	
	//Function to set comment by
	void SetCommentBy(Object* UserKaObj)
	{
		CommmentedBy = UserKaObj;
	}

	//Function for printing the comments
	void PrintComments()
	{
		cout << "\t\t" ;
		CommmentedBy->PrintNameOnly();  
		cout << " wrote: ";
		cout /*<< "\""*/ << Message /*<< "\""*/ << endl;
	}
};

//Post wali class
class Post : public Object
{
private:
	int Type;
	int NoOfLikes;
	int NoOfComments;
	char* PostID;
	char* Text;
	Object* SharedBy;
	Object** LikedBy;
	Date SharedDate;
	Comment** comment;
	Activity* activity;

public:

	static int TotalPosts;

	//constructor
	Post() 
	{
		Type = 0;
		NoOfLikes = 0;
		NoOfComments = 0;
		PostID = NULL;
		Text = NULL;
		SharedBy = NULL;
		LikedBy = NULL;
		comment = NULL;
		activity = NULL;
		
		comment = new Comment * [10];
		for (int i = 0; i < 10; i++) 
		{
			comment[i] = NULL;
		}
	}

	//destructor
	~Post()
	{
		if (PostID)
			delete[] PostID;
		if (Text)
			delete[] Text;
		if (SharedBy)
			delete SharedBy;
		if (LikedBy)
			delete LikedBy;
		if (activity)
			delete activity;
		if (comment) {
			for (int i = 0; i < 10; i++)
				delete comment[i];
		}
	}

	//Function to read posts data from file
	void ReadPostsFromFile(ifstream& fin) 
	{
		fin >> Type;
		char Temp[100] = { '\0' };
		fin >> Temp;
		PostID = Helper::GetStringFromBuffer(Temp);

		SharedDate.ReadDateFromFile(fin);
		fin.ignore();
		fin.getline(Temp, 100, '\n');
		Text = Helper::GetStringFromBuffer(Temp);
		if (Type == 2)
		{
			activity = new Activity;
			activity->ReadActivityFromFile(fin);
		}
	}

	//Getters
	char* GetID()
	{
		return PostID;
	}

	Object* GetSharedBy()
	{
		return SharedBy;
	}

	Date GetPostDate()
	{
		return SharedDate;
	}

	//Setters
	virtual void SetValues(Post* p_pTR, char* posttext, Object* userPtr, char* ID) {}

	void SetNoofLikes(int n) 
	{
		NoOfLikes = n;
	}

	void SetSharedby(Object* ID_obj) 
	{
		if (SharedBy == NULL) 
		{
			SharedBy = ID_obj;
		}
	}
	void SetLikedBy(Object*& Like) 
	{
		if (LikedBy == 0) 
		{
			LikedBy = new Object * [10];
			for (int i = 0; i < 10; i++)
			{
				LikedBy[i] = 0;
			}
		}

		if (NoOfLikes <= 10)
		{
			for (int i = 0; i < NoOfLikes; i++)
			{
				if (LikedBy[i] == NULL)
				{
					if (LikedBy[i] != Like) 
					{
						LikedBy[i] = Like;
						NoOfLikes++;
						break;
					}
				}
			}
		}
		else
		{
			cout << endl << "Maximum No.of likes Have Been Liked" << endl;
		}
	}

	void SetText(char* mystring)
	{
		Text = Helper::GetStringFromBuffer(mystring);
	}

	void SetComment(Comment*& temp_comment)
	{
		if (NoOfComments <= 10)
		{
			for (int i = 0; i < 10; i++) 
			{
				if (comment[i] == NULL) 
				{
					comment[i] = temp_comment;
					break;
				}
			}
		}
	}

	void SetDate(Date Date)
	{
		SharedDate = Date;
	}

	void LikeIncrement()
	{
		NoOfLikes++;
	}
	void CommentIncrement()
	{
		NoOfComments++;
	}
	
	//Function to add comments
	void AddComment(Comment* _comment)
	{
		for (int i = 0; i < 10; i++)
		{
			if (comment[i] == NULL)
			{
				comment[i] = new Comment;
				comment[i]->SetID(_comment->GetID());
				comment[i]->SetText(_comment->GetText());
				comment[i]->SetCommentBy(_comment->GetCommentBy());
				break;
			}
		}
	}

	//Function to print liked list
	void ViewLikedList()
	{
		cout << "Post Liked By : " << endl<<endl;
		for (int i = 0; i < 10; i++)
		{
			if (LikedBy[i] != nullptr)
			{
				cout << LikedBy[i]->GetID()<<" - ";
				LikedBy[i]->PrintNameOnly();
				cout << endl;
			}
		}
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
	}

	//function for printing the posts
	void ViewPost() 
	{
		cout << "---";
		SharedBy->PrintNameOnly();
		if (Type == 2) 
		{
			activity->ActivityPrint();
		}
		else
		{
			cout << " shared ";
		}
		cout << " \"" << Text << "\""<<endl;

		for (int i = 0; comment[i] != nullptr; i++)
		{
			if (comment[i] != 0)
				comment[i]->PrintComments();

		}
	}

	//function for printing the timeline
	void ViewTimeLine()
	{
		cout << "---";
		SharedBy->PrintNameOnly();
		if (Type == 2)
		{
			activity->ActivityPrint();
		}
		else
		{
			cout << " shared a memory " << endl;
		}
		cout << " \"" << Text << "\"..." ;

		SharedDate.PrintDate();

		for (int i = 0; comment[i] != nullptr; i++)
		{
			if (comment[i] != 0)
				comment[i]->PrintComments();

		}
	}

	//Function for printing the page
	void ViewPage()
	{
		cout << "---";
		SharedBy->PrintNameOnly();
		if (Type == 2)
		{
			activity->ActivityPrint();
		}
		else
		{
			cout << " shared a memory " << endl;
		}
		SharedDate.PrintDate();
		cout << " \"" << Text << "\"..."<<endl;

		for (int i = 0; comment[i] != nullptr; i++)
		{
			if (comment[i] != 0)
				comment[i]->PrintComments();

		}
	}

	
};

//Page ki class
class Page : public Object
{
private:
	char* NameOfPage;
	Post** TimeLine;
	int NoOfPostsShared = 0;

public:

	static int TotalPages;
	// constructor
	Page()
	{
		NameOfPage = NULL;
		TimeLine = NULL;
		NoOfPostsShared = 0;
		
		TimeLine = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			TimeLine[i] = new Post;
			TimeLine[i] = NULL;
		}
	}

	//destructor
	~Page()
	{
		if (NameOfPage)
		{
			delete[] NameOfPage;
		}

		for (int i = 0; i < NoOfPostsShared; i++)
		{
			delete TimeLine[i];
		}			
		delete[] TimeLine;
	}

	//Function to read pages file data
	void ReadPagesFromFile(ifstream& fin)
	{
		char Temp[100] = { '\0' };
		fin >> Temp;
		SetId(Temp);
		fin.getline(Temp, 100);
		NameOfPage = Helper::GetStringFromBuffer(Temp);
	}

	//Function to get the no. of posts
	int Getnumofposts()
	{
		return NoOfPostsShared;
	}

	//function for printing the name only
	void PrintNameOnly()
	{
		cout << NameOfPage;
	}

	//Function to print the id and name
	void printName()
	{
		cout << GetID() << " - " << NameOfPage;
	}

	//Function for printing the complete page
	void ShowPage()
	{
		cout << NameOfPage << endl << endl;
		for (int i = 0; TimeLine[i] != nullptr; i++)
		{
			TimeLine[i]->ViewPage();
			cout << endl;
		}
	}

	//function to set post
	void SetPost(Post*& newpost)
	{
		if (NoOfPostsShared <= 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (TimeLine[i] == NULL)
				{
					TimeLine[i] = newpost;
					break;
				}
			}
		}
		else
		{
			cout << endl << "Maximum No. of Liked posts have been reached" << endl;
		}
			
	}

	//Function to print the entire timeline
	void ShowTimeline()
	{
		cout << NameOfPage << endl << endl;
		for (int i = 0; TimeLine[i] != nullptr; i++)
		{
			TimeLine[i]->ViewTimeLine();
			cout << endl;
		}
	}

	//Function for adding post to the timeline
	void AddPostToTimeline(Post* Ptr)
	{
		NoOfPostsShared++;
		TimeLine[NoOfPostsShared] = Ptr;
	}

	//Function that increase the count of shared posts
	void SharedPostIncrement() 
	{
		NoOfPostsShared++;
	}

	//Function for printing the current post
	void ShowCurrentPost() 
	{
		Date currentdate = Date::GetCurrentDate();
		Date previousdate(currentdate.GetDay() - 1, currentdate.GetMonth(), currentdate.GetYear());
		for (int i = 0; i < 10; i++)
		{
			if (TimeLine[i] == NULL) 
			{
				break;
			}
			else if (TimeLine[i]->GetPostDate() == previousdate || TimeLine[i]->GetPostDate() == currentdate)
			{
				TimeLine[i]->ViewPost();
				cout << endl;
			}
		}
	}
};
int Page::TotalPages = 0;

int Post::TotalPosts = 0;

//Memory ki class
class Memory : public Post 
{
private:
	Post* SharedPost;

public:

	//constructor
	Memory() 
	{
		SharedPost = NULL;
	}

	//Destructor
	~Memory()
	{
		delete SharedPost;
	}

	//Function to set the values
	void SetValues(Post* postptr, char* posttext, Object* userPtr, char* id) 
	{
		SharedPost = postptr,

			this->SetId(id);
		this->SetText(posttext);
		this->SetSharedby(userPtr);
		this->SetDate(Date::GetCurrentDate());
	}
	

};

//User wali class
class User : public Object
{
private:
	char* FirstName;
	char* LastName;
	User** FriendsList;
	Page** LikedPages;
	int FriendsCount;
	int LikedPagesCount;
	Post** Timeline;
	int NoOfharedPosts;

public:

	static int TotalUsers;

	//constructor
	User()
	{
		FirstName = NULL;
		LastName = NULL;
		FriendsList = NULL;
		LikedPages = NULL;
		FriendsCount = 0;
		LikedPagesCount = 0;
		NoOfharedPosts = 0;
		Timeline = new Post * [12];
		int j = 0;
		for (int i = 0; i < 12; i++)
		{
			Timeline[i] = nullptr;
		}
	}

	//Destructor
	~User()
	{
		if (FirstName != NULL)
		{
			delete[] FirstName;
		}		
		if (LastName != NULL)
		{
			delete[] LastName;
		}	
		if (FriendsList != 0)
		{
			delete[]FriendsList;
		}
		if (LikedPages != 0)
		{
			delete[]LikedPages;
		}	
		for (int i = 0; i < NoOfharedPosts; i++)
		{
			if (Timeline[i] != nullptr)
			{
				delete Timeline[i];
			}	
		}
		delete[]Timeline;
	}

	//Getters
	int GetTotalFriends()
	{
		return FriendsCount;
	}

	int GetLikedPages() 
	{
		return LikedPagesCount;
	}

	//Setter
	void SetTotalFriends(int Ns)
	{
		FriendsCount = Ns;
	}
	void SetterTotalLikedPages(int Ns) {
		LikedPagesCount = Ns;
	}
	void likedPageIncrement() {
		LikedPagesCount++;
	}
	void SharedPostIncrement() {
		NoOfharedPosts++;
	}

	//Function to set post
	void SetPost(Post*& newpost) 
	{
		if (NoOfharedPosts <= 10) 
		{
			for (int i = 0; i < 10; i++) 
			{
				if (Timeline[i] == NULL) 
				{
					Timeline[i] = newpost;
					break;
				}
			}
		}
		else
		{
			cout << endl << "Liked Page Reached to Maximum Capacity" << endl;
		}
	}

	//Function to print full name and id
	void printsuerName()
	{
		cout << GetID() << " - " << FirstName <<" "<< LastName;
	}

	//Function to print the full name
	void PrintNameOnly()
	{
		cout << FirstName << " " << LastName;
	}
	//Function to read the data of users from file
	void ReadUsersFromFile(ifstream& fin)
	{
		char buffer[80] = { '\0' };
		fin >> buffer;
		SetId(buffer);
		fin >> buffer;
		FirstName = Helper::GetStringFromBuffer(buffer);
		fin >> buffer;
		LastName = Helper::GetStringFromBuffer(buffer);
	}

	//Function to print full name only
	void printName() {
		cout << FirstName << " " << LastName;
	}
	
	//Function for adding post to the timeline
	void AddPostToTimeline(Post* Ptr)
	{
		Timeline[NoOfharedPosts] = Ptr;
		NoOfharedPosts++;
	}

	//Function of liked pages
	void LikePage(Page*& newPage)
	{
		if (LikedPages == 0)
		{
			LikedPages = new Page * [10];
			for (int i = 0; i < 10; i++)
			{
				LikedPages[i] = 0;
			}
		}
		if (LikedPagesCount <= 10)
		{
			for (int i = 0; i < LikedPagesCount; i++)
			{
				if (LikedPages[i] == NULL) {
					LikedPages[i] = newPage;
					break;
				}
			}
		}
		else
		{
			cout << endl << "Maximum Page count of liked pages  has reached" << endl;
		}
	}

	//Function for allocation
	void Allocate_friendlist()
	{
		FriendsList = new User * [FriendsCount];
		for (int i = 0; i < FriendsCount; i++)
		{
			FriendsList[i] = new User;
		}
	}

	//Function to add users
	void AddFriend(User*& newFriend)
	{
		if (FriendsList == 0)
		{
			FriendsList = new User * [10];
			for (int i = 0; i < 10; i++)
			{
				FriendsList[i] = 0;
			}
		}

		if (FriendsCount <= 10)
		{
			for (int i = 0; i < FriendsCount; i++)
			{
				if (FriendsList[i] == NULL) 
				{
					FriendsList[i] = newFriend;
					break;
				}
			}
		}
		else 
		{
			cout << endl << "Liked Pages have reached to Max Count" << endl;
		}
	}

	//Function to print friendslist
	void ViewFriendList()
	{
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;

		this->printName();
		cout << " - Friend List" << endl << endl;
		for (int i = 0; FriendsList[i] != NULL; i++)
		{
			if (FriendsList[i]) 
			{
				cout << FriendsList[i]->GetID() << " - ";
				FriendsList[i]->printName();
				cout << endl;
			}
		}
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;

		cout << endl;
	}

	//Function to print the page list
	void ViewPagesList() 
	{
		cout << "------------------------------------------------------------" << endl;
		this->PrintNameOnly();
		cout << "Liked Pages" << endl << endl;
		for (int j = 0; j < LikedPagesCount; j++)
		{
			if (LikedPages[j]) 
			{
				LikedPages[j]->printName();
				cout << endl;
			}
		}
	}

	//Function to print the liked pages
	void ShowLikedPages() 
	{
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		this->PrintNameOnly();
		cout << " - Liked Pages " << endl << endl;
		for (int i = 0; i < LikedPagesCount; i++)
		{
			LikedPages[i]->printName();
			cout << endl;
		}
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl << endl;
	}

	//Function to print the timeline
	void ShowTimeline()
	{
		
		cout << FirstName << " " << LastName << " - Time Line" << endl << endl;
		
		int i = 0;
		for (int i = 0; Timeline[i] != NULL; i++) 
		{
			
			Timeline[i]->ViewTimeLine();
			cout << endl;
		}
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;

	}

	//Function to print the memory
	void SeeYourMemory()
	{
		Date current = Date::GetCurrentDate();
		for (int i = 0; i < 10; i++)
		{
			if (Timeline[i] != nullptr)
			{
				Date postdate = Timeline[i]->GetPostDate();
				if (current.GetDay() == postdate.GetDay() && current.GetMonth() == postdate.GetMonth() && current.GetYear() > postdate.GetYear())
				{
					cout << endl << "We hope you enjoy looking back and sharing your memories on Facebook, from most recent to long ago." << endl << endl;
					cout << "On this Day" << endl;
					cout << current.GetYear() - postdate.GetYear() << " Years ago" << endl;
					Timeline[i]->ViewTimeLine();
				}
			}
		}
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	}

	//Function to print home
	void ViewHome() 
	{
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		PrintNameOnly();
		cout << " - Home Page" << endl << endl;
		Date currentdate = Date::GetCurrentDate();
		Date previousdate(currentdate.GetDay() - 1, currentdate.GetMonth(), currentdate.GetYear());
		for (int i = 0; i < 10; i++) 
		{
			if (FriendsList[i] == nullptr)
				break;
			else
			{
				for (int j = 0; j < 10; j++) 
				{

					if (FriendsList[i]->Timeline[j] == nullptr)
						break;
					else 
					{
						if (FriendsList[i]->Timeline[j]->GetPostDate() == currentdate || FriendsList[i]->Timeline[j]->GetPostDate() == previousdate)
						{
							FriendsList[i]->Timeline[j]->ViewPost();
							cout << endl;
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {

			if (LikedPages[i] == nullptr)
				break;
			else
				LikedPages[i]->ShowCurrentPost();
		}

	}
	

};
int User::TotalUsers = 0;

//Using template for deallocation
template<class T>
static void Deallocation(T** List, int Count)
{
	for (int i = 0; i < Count; i++)
	{
		delete List[i];
	}
	delete[]List;
}

//Facebook wali calss
class Facebook
{
private:
	int TotalPages;
	int TotalPosts;
	int TotalUsers;
	int TotalComments;
	Page** Pages;
	User** Users;
	Post** Posts;

public:

	// Constructor of class Facebook
	Facebook() 
	{
		TotalPages = 0;
		TotalPosts = 0;
		TotalUsers = 0;
		TotalComments = 0;
		Pages = NULL;
		Users = NULL;
		Posts = NULL;
	}

	// Fuction of class Facebook that loads all the files.
	void LoadData() 
	{
		LoadPages("pages.txt");
		LoadUsers("user.txt");
		LoadPosts("post.txt");
		LoadComments("comment.txt");
	}

	// Function that Loads the pages file
	void LoadPages(const char* PagesWaliFile)
	{
		ifstream FinPage(PagesWaliFile);
		if (FinPage.is_open())
		{
			int TotalNoOfPages = 0;
			FinPage >> TotalPages;
			Pages = new Page * [TotalPages];
			for (int i = 0; i < TotalPages; i++)
			{
				Pages[i] = new Page;
				Pages[i]->ReadPagesFromFile(FinPage);
			}
			FinPage.close();
		}
		else
		{
			cout << endl << "Unable to Open the File or File not Found" << endl;
		}
	}

	//Function that search a user by its id.
	User* SearchUserbyID(const char* UserID)
	{
		for (int i = 0; i < TotalUsers; i++)
		{
			if (Helper::isEqual(Users[i]->GetID(), UserID) == 1)
			{
				return Users[i];
			}
		}
		return nullptr;
	}

	//Function that search a page by its id.
	Page* SearchPagebyID(char* ID_pages) {
		for (int i = 0; i < TotalUsers; i++) {
			if (Helper::isEqual(Pages[i]->GetID(), ID_pages) == 1) {
				return Pages[i];
			}
		}
		return nullptr;
	}

	//Function to Load Data of Users File.
	void LoadUsers(const char* UsersWaliFile)
	{
		ifstream FinUsers(UsersWaliFile);
		if (FinUsers.is_open())
		{
			FinUsers >> TotalUsers;
			Users = new User * [TotalUsers];
			char*** TempFriends = new char** [TotalUsers];
			for (int i = 0; i < TotalUsers; i++)
			{
				Users[i] = new User;
				Users[i]->ReadUsersFromFile(FinUsers);

				TempFriends[i] = new char* [10];

				char Temp[30]{};
				int j = 0;
				while (Temp[0] != '-')
				{
					FinUsers >> Temp;
					TempFriends[i][j++] = Helper::GetStringFromBuffer(Temp);
				}
				Users[i]->SetTotalFriends(j);

				char Temp1[30]{};
				while (Temp1[0] != '-') 
				{
					FinUsers >> Temp1;
					char* idcheck = Helper::GetStringFromBuffer(Temp1);
					if (Temp1[0] != '-') {
						Page* pagePTR = SearchPagebyID(idcheck);
						Users[i]->likedPageIncrement();
						Users[i]->LikePage(pagePTR);
					}
				}
			}
			FinUsers.close();

			for (int i = 0; i < TotalUsers; i++)
			{
				for (int j = 0; j < Users[i]->GetTotalFriends(); j++) 
				{

					User* userptr = SearchUserbyID(TempFriends[i][j]);
					Users[i]->AddFriend(userptr);
				}
			}
			Deallocatetemp(TempFriends, TotalUsers);
		}
		else
		{
			cout << "Unable to open the File oe file not found."<<endl;
		}
	}

	//Function that search a object by its id.
	Object* SearchObjectByID(char* id) {
		if (id[0] == 'u') {
			Object* userptr = SearchUserbyID(Helper::GetStringFromBuffer(id));
			return userptr;
		}
		else if (id[0] == 'p') {
			Object* pageptr = SearchPagebyID(Helper::GetStringFromBuffer(id));
			return pageptr;
		}
		else {
			return NULL;
		}
	}

	//Function that search a post by its id.
	Post* search_PostById(char* id) {
		for (int i = 0; i < TotalPosts; i++) {

			if (Helper::isEqual(Posts[i]->GetID(), id)) {
				return Posts[i];				//retuning the object with req ID
			}
		}
		return NULL;
	}

	//Function to Load Data of Posts File.
	void LoadPosts(const char* PostsWaliFile)
	{
		ifstream FinPosts(PostsWaliFile);
		if (FinPosts.is_open())
		{
			FinPosts >> TotalPosts;
			Posts = new Post * [TotalPosts];
			for (int i = 0; i < TotalPosts; i++) 
			{
				Posts[i] = new Post;
				Posts[i]->ReadPostsFromFile(FinPosts);
				char Temp[80] = { '\0' };

				FinPosts >> Temp;

				Object* Ptr = SearchObjectByID(Temp);
				Posts[i]->SetSharedby(Ptr);
				Ptr->SetPost(Posts[i]);

				char TempLikers[50] = { '\0' };
				//reading likers
				while (TempLikers[0] != '-')
				{
					FinPosts >> TempLikers;

					Object* likerptr = SearchObjectByID(TempLikers);
					Posts[i]->LikeIncrement();
					Posts[i]->SetLikedBy(likerptr);
				}
			}
			FinPosts.close();
		}
		else {
			cout << "Unable to open the file or file not found"<<endl;
		}
	}

	// Function to Increment the count of Total Comments.
	void CommentIncrement()
	{
		TotalComments++;
	}

	//Function to Load Data of Comments File.
	void LoadComments(const char* CommentsWaliFile) {
		ifstream FinComments(CommentsWaliFile);

		if (FinComments.is_open())
		{
			FinComments >> TotalComments;
			char Temp[100] = { '\0' };
			char Temp1[30] = { '\0' };

			for (int i = 0; i < TotalComments; i++) {
				Comment* commentptr = new Comment;

				FinComments >> Temp;
				commentptr->SetID(Helper::GetStringFromBuffer(Temp));
				FinComments >> Temp;
				Post* ptr = search_PostById(Helper::GetStringFromBuffer(Temp));

				ptr->SetComment(commentptr);
				ptr->CommentIncrement();
				FinComments >> Temp1;

				Object* commentbyPTR = SearchObjectByID(Helper::GetStringFromBuffer(Temp1));
				commentptr->SetCommentBy(commentbyPTR);

				FinComments.getline(Temp, 100);
				commentptr->SetText(Helper::GetStringFromBuffer(Temp));
			}
		}
		else
			cout << endl << "Unable to open the file or file not found" << endl;
	}

	//Function to display share memory.
	void ShareMemory(char* postid, char* posttext, User* currentUser) 
	{
		cout << "Command : \tShareMemory(" << postid << "," << posttext << ")" << endl;
		Post* P = search_PostById(postid);
		Post* memoryptr = new Memory;
		char temppostid[9] = "post";
		char* IDtoSet = Helper::Concatenate(temppostid, Helper::int_to_char(TotalComments));
		memoryptr->SetValues(P, posttext, currentUser, IDtoSet);
		currentUser->SetPost(memoryptr);
	}

	//Function to Deallocate the temporary memory.
	void Deallocatetemp(char*** tempList, int n)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < Users[i]->GetTotalFriends(); j++) 
			{
				delete[]tempList[i][j];
				tempList[i][j] = 0;
			}

		}
		delete[] tempList;
		tempList = 0;
	}

	//Function That set and print the current date
	void SetCurrentDate(int d, int m, int y) 
	{
		Date::SetCurrentDate(d, m, y);
		cout << "System Date:\t";
		Date::GetCurrentDate().PrintDate();
	}

	//Function that display the liked list.
	void ShowLikedList(char* postid)
	{
		Post* currentpost = 0;
		currentpost = search_PostById(postid);
		cout << "-------------------------------------------------------------------------------------------" << endl;

		if (currentpost != nullptr)
			currentpost->ViewLikedList();
		else
			cout << "\nPost Not Available" << endl;
	}

	//Function to display the post comments.
	void PostComment(char* postid, char* commenttext, User* userptr) 
	{
		
		cout << "Command:\tPostComment(" << postid << ", " << commenttext << ")" << endl;
		cout << "Command:\tViewPost(" << postid << ")" << endl;
		Facebook::CommentIncrement();

		Comment* commentptr = new Comment;
		char tempid[4] = "c";
		commentptr->SetID(Helper::Concatenate(tempid, Helper::int_to_char(TotalComments)));
		commentptr->SetText(commenttext);
		commentptr->SetCommentBy(userptr);
		Post* postcommentptr = search_PostById(postid);
		postcommentptr->AddComment(commentptr);
		delete commentptr;
		cout << endl;
		postcommentptr->ViewPost();
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	}

	//Function that handles the whole diplay and printing .
	void Running()
	{
		int day = 15, month = 11, year = 2017;
		cout << "Command:\tSet current System Date " << day << " " << month << " " << year << endl;

		SetCurrentDate(day, month, year);

		char User1[] = "u7";
		cout << "\n\nCommand:\tSet Current User " << "'" << User1 << "'" << endl;

		User* currentUser = 0;
		currentUser = SearchUserbyID(User1);
		if (currentUser != 0) {

			currentUser->PrintNameOnly();
			cout << " successfully set as Current User" << endl << endl;


			cout << "\nCommand:\tView Friend List" << endl;
			currentUser->ViewFriendList();
			
			cout << "\nCommand:\tViewLikedPages " << endl;
			currentUser->ShowLikedPages();


			cout << "Command: \tView Home" << endl;
			currentUser->ViewHome();
			
			cout << "---------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\nCommand:\t ViewTimeLine" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------" << endl;

			currentUser->ShowTimeline();


			char Postnum[] = "post5";

			Post* currentpost = 0;
			currentpost = search_PostById(Postnum);
			
			if (currentpost != 0)
			{
				cout << "Command:\tViewlikedlist(post5)\n";

				currentpost->ViewLikedList();
				
				cout << "command:\tLikePost(" << Postnum << ")" << endl;

				Object* Current_usernow = currentUser;
				currentpost->SetLikedBy(Current_usernow);
				cout << "Command:\tViewLikedList(post5)\n";
				currentpost->ViewLikedList();
			}
			else 
			{
				cout << "\nPost Not Available" << endl;
			}

			char postid[] = "post4";
			char addcomment[] = "Good Luck For Your Result";
			PostComment(postid, addcomment, currentUser);

			char postid1[] = "post8";
			char addcomment1[] = "Thanks for the wishes.";

			PostComment(postid1, addcomment1, currentUser);

			
			cout << "Command: \tSeeYourMemories" << endl;
			currentUser->SeeYourMemory();



			char postname[] = "post10";
			char memorytext[] = "\"Never thought I will be specialist in this field...\"";
			ShareMemory(postname, memorytext, currentUser);
			cout << "\nCommand:\t ViewTimeLine" << endl;
			currentUser->ShowTimeline();

			char Pageid_[] = "p1";
			cout << "Command:\tViewPage(" << Pageid_ << ")" << endl;
			Page* Current_Pages = SearchPagebyID(Pageid_);

			if (Current_Pages != 0)
				Current_Pages->ShowPage();
			else
				cout << "\nPage Not Found\n";
			cout << "---------------------------------------------------------------------------------------------------------------" << endl;
			
		}

		else 
		{
			cout << "\nUser Not Found\n";
		}

		char User2[] = "u11";
		cout << "\n\nCommand:\tSet Current user  " << User2 << endl;

		User* currentUser2 = 0;
		currentUser2 = SearchUserbyID(User2);
		if (currentUser2 != 0)
		{
			currentUser2->PrintNameOnly();
			cout << "  successfully set as Current User" << endl << endl;

			cout << endl << "Command : \tView Home\n";
			currentUser2->ViewHome();
			cout << "---------------------------------------------------------------------------------------------------------------" << endl;


			cout << "\nCommand : ViewTimeLine" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------" << endl;
			currentUser2->ShowTimeline();
			
		}
		else
			cout << User2 << " not found" << endl;

	}

	//Destructor of class Facebook
	~Facebook()
	{
		Deallocation(Pages, TotalPages);
		Deallocation(Users, TotalUsers);
	}
};



int main()
{

	Facebook Fb;
	Fb.LoadData();
	Fb.Running();

	system("pause");
	return 0;
}