/******************************************************************************

Classes by Neevan Abedin
Interactive media database that a user can add to or delete from
3.21.2021

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>

//header files
#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"

using namespace std;

//function prototypes
void ADD(vector<Media*>* media);
void SEARCH(char* title, vector<Media*>* media);
void DELETE(char* title, vector<Media*>* media);
void SEARCH(int year, vector<Media*>* media);
void DELETE(int year, vector<Media*>* media);

int main() {
  bool running = true;
  char input[10];
  char title[30]; //for title input
  int year; //for year input
  //media vector
  vector<Media*> mediaList;
  while(running) {
    cout << "What would you like to do?: ADD, SEARCH, DELETE, or QUIT " << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "add") == 0 || strcmp(input, "ADD") == 0) {
      // ADD
      ADD(&mediaList);
    }
    else if(strcmp(input, "search") == 0 || strcmp(input, "SEARCH") == 0) {
      // SEARCH
      cout << "Search by title or year?" << endl;
      cin.get(input, 6);
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0) {
	cout << "Input title: " << endl;
	cin.get(title, 30);
	cin.clear();
	cin.ignore(10000, '\n');
	//run search using char* title
	SEARCH(title, &mediaList);
      }
      else if(strcmp(input, "year") == 0) {
	cout << "Input year: " << endl;
	cin >> year;
	cin.clear();
	cin.ignore(10000, '\n');
	//run search using int year
	SEARCH(year, &mediaList);
      }
    }
    else if(strcmp(input, "delete") == 0 || strcmp(input, "DELETE") == 0) {
      // DELETE
      cout << "Delet by title or year?" << endl;
      cin.get(input, 6);
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0) {
	cout << "Input title: " << endl;
	cin.get(title, 30);
	cin.clear();
	cin.ignore(10000, '\n');
	//run delete using char* title
	DELETE(title, &mediaList);
      }
      else if(strcmp(input, "year") == 0) {
	cout << "Input year: " << endl;
	cin >> year;
	cin.clear();
	cin.ignore(10000, '\n');
	//run delete using int year
	DELETE(year, &mediaList);
      }
    }
    else if(strcmp(input, "quit") == 0 || strcmp(input, "QUIT") == 0) {
      running = false; //quit program
    }
    //if input is invalid
    else {
      cout << "Invalid input! Please enter ADD, SEARCH, DELETE, or QUIT." << endl;
    }
  }
  return 0;
}

//ADD function
void ADD(vector<Media*>* media) {
  char input[30];
  cout << "What kind of media will you add? movie, videogame, or music?" << endl;
  cin.get(input, 12);
  cin.clear();
  cin.ignore(10000, '\n');
  //input = movie
  if(strcmp(input,"movie") == 0) {
    Movie* movie = new Movie();
    cout << "Input title: " << endl;
    cin.get(movie->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input year: " << endl;
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input director: " << endl;
    cin.get(movie->getDirector(), 30);
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Input duration (minutes): " << endl;
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input rating (out of 5 stars): " << endl;
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(movie);
  }
   //video games
  else if(strcmp(input, "videogame") == 0) {
    Videogame* videogame = new Videogame();
    cout << "Input title: " << endl;
    cin.get(videogame->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input year: " << endl;
    cin >> *videogame->getYear();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input publisher: " << endl;
    cin.get(videogame->getPublisher(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input rating (out of 5 stars): " << endl;
    cin >> *videogame->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(videogame);
  }
  //music
  else if(strcmp(input, "music") == 0) {
    Music* music = new Music();
    cout << "Input title: " << endl;
    cin.get(music->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input artist: " << endl;
    cin.get(music->getArtist(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input duration (seconds): " << endl;
    cin >> *music->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Input publisher: " << endl;
    cin.get(music->getPublisher(), 30);
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(music);
  }
  //invalid input
  else {
    cout << "Invalid media type :(" << endl;
  }
}

//search funtion
void SEARCH(char* title, vector<Media*>* media) {
  vector<Media*>::iterator iter;
  for (iter = media->begin(); iter != media->end(); ++iter) {
    if (strcmp(title, (*iter)->getTitle()) == 0) {
      cout << (*iter)->getTitle() << ", ";
      cout << *(*iter)->getYear() << endl;
      //if it is a movie
      if((*iter)->getType() == 0) {
        cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
        cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
        cout << "  Rating at " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars out of 5" << endl << endl;
      }
      //if it is music
      else if((*iter)->getType() == 1) {
        cout << "  Music by artist " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
	cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
        cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl; 
      }
      //if it is a videogame
      else if((*iter)->getType() == 2) {
        cout << "  Publisheb by " << dynamic_cast<Videogame*>(*iter)->getPublisher() << endl;
	cout << "  Rating of " << *dynamic_cast<Videogame*>(*iter)->getRating() << " stars out of 5" << endl;
      }
    }
  }
}

//same as search, int instead of char*
void SEARCH(int year, vector<Media*>* media) {
  vector<Media*>::iterator iter;
  for(iter = media->begin(); iter != media->end(); ++iter) {
    if(year == *(*iter)->getYear()) {
      cout << (*iter)->getTitle() << ", ";
      cout << *(*iter)->getYear() << endl;
      //if movie
      if((*iter)->getType() == 0) {
        cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
        cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
        cout << "  Rating at " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars out of 5" << endl << endl;
      }
      //if music
      else if((*iter)->getType() == 1) {
        cout << "  Music by artist " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
        cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
        cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
      }
      //if game
      else if((*iter)->getType() == 2) {
        cout << "  Publisheb by " << dynamic_cast<Videogame*>(*iter)->getPublisher() << endl;
        cout << "  Rating of " << *dynamic_cast<Videogame*>(*iter)->getRating() << " stars out of 5" << endl;
      }
    }
  }
}

//delete function
void DELETE(char* title, vector<Media*>* media) {
  char input[4]; //for yes/no
  vector<Media*>::iterator iter;
  //similar to search funtion
  for(iter = media->begin(); iter != media->end(); ++iter) {
    if(strcmp(title, (*iter)->getTitle()) == 0) {
      cout << (*iter)->getTitle() << ", ";
      cout << *(*iter)->getYear() << endl;
      //if movie
      if((*iter)->getType() == 0) {
        cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
        cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
        cout << "  Rating at " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars out of 5" << endl << endl;
      }
      //if music
      else if((*iter)->getType() == 1) {
        cout << "  Music by artist " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
        cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
        cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
      }
      //if game
      else if((*iter)->getType() == 2) {
        cout << "  Publisheb by " << dynamic_cast<Videogame*>(*iter)->getPublisher() << endl;
        cout << "  Rating of " << *dynamic_cast<Videogame*>(*iter)->getRating() << " stars out of 5" << endl;
      }
      //delete 
      cout << "Delete this media? 'yes' or 'no' " << endl;
      cin.get(input, 4);
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "yes") == 0) {
	//delete
	delete *iter;
	iter = media->erase(iter);
	return;
      }
    }
  }
}

//same as delete
void DELETE(int year, vector<Media*>* media) {
  char input[5]; //for yes/no
  vector<Media*>::iterator iter;
  for (iter = media->begin(); iter != media->end(); ++iter) {
    if (year == *(*iter)->getYear()) {
       cout << (*iter)->getTitle() << ", ";
      cout << *(*iter)->getYear() << endl;
      //if it is a movie
      if((*iter)->getType() == 0) {
        cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
        cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
        cout << "  Rating at " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars out of 5" << endl << endl;
      }
      //if it is music
      else if((*iter)->getType() == 1) {
        cout << "  Music by artist " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
        cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
        cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
      }
      //if it is a videogame
      else if((*iter)->getType() == 2) {
        cout << "  Publisheb by " << dynamic_cast<Videogame*>(*iter)->getPublisher() << endl;
        cout << "  Rating of " << *dynamic_cast<Videogame*>(*iter)->getRating() << " stars out of 5" << endl;
      }
      //delete code
      cout << "Delete this media? 'yes' or 'no' " << endl;
      cin.get(input, 4);
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "yes") == 0) {
        //delete
        delete *iter;
        iter = media->erase(iter);
        return;
      }
    }
  }
}