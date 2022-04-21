/*
FCAI - Programing 1 - 2022 - Assignment 3
Program Name : Photoshop 
Program Description : Apply filters on images
 Author1: Ahmed Mohamed Hany 20210038
 Author2: ahmed Alaa Mohamed 20210027
 Author3: Omnia Magdy abdelnaby 20211018
 Date: 5-4-2022
 Version: 1.0
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
//declear image array
unsigned char image[SIZE][SIZE];

//declear functions
void loadImage();
void saveImage();

void filter1(); //Black and white
void filter2(); //Invert filter
void filter3(); //Merge filter
void filter4(); //Flip Filter
void filter5(); //Rotate Filter
void filter6(); //Darken and Lighten
void filter7(); //Detect image Filter
void filter8(); //Enlarge image Filter
void filter9(); //shrink image Filter
void filtera(); //Mirror 1/2 Image filter
void filterb(); //shuffle image filter
void filterc(); //Blur Filter

int main()
{
    char userinput;
    bool runner = true;
    cout << "Ahlan ya user ya habiby\n";
    loadImage(); //call load image function
    while (runner)
    {
        //choices of filters to apply
        cout << "\nPlease select a filter to apply or 0 to exit:\n1-Black & White Filter\n2-Invert Filter\n"
             << "3-Merge Filter\n4-Flip Filter\n5-Rotate Image\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image\n"
             <<"9-Shrink Image\na-Mirror 1/2 Image\nb-Shuffle Image\nc-Blur Image\ns-Save the image to a file\n0-Exit\n";
        cout << "Your Choice : ";
        cin >> userinput; // take from user his choice
        switch (userinput) //switch statment for the choice
        {
        case '1':
            filter1(); //call filter 1 function
            cout << "_________________Black & White Done____________________\n\n";
            break;
        case '2':
            filter2(); //call filter 2 function
            cout << "_________________Invert Done____________________\n\n";
            break;
        case '3':
            filter3(); //call filter 3 function
            cout << "_________________Merge Done____________________\n\n";
            break;
        case '4':
            filter4(); //call filter 4 function
            cout << "_________________Flip Done____________________\n\n";
            break;
        case '5':
            filter5(); //call filter 5 function
            cout << "_________________Rotate Done____________________\n\n";
            break;
        case '6':
            filter6(); //call filter 6 function
            cout << "_________________Darken and Lighten Done____________________\n\n";
            break;
        case '7':
            filter7(); //call filter 7 function
            cout << "_________________Detect Image Edge Done____________________\n\n";
            break;
        case '8':
            filter8(); //call filter 8 function
            cout << "_________________Enlarge Done____________________\n\n";
            break;
        case '9':
            filter9(); //call filter 9 function
            cout << "_________________Shrink Done____________________\n\n";
            break;
        case 'a':
            filtera(); //call filter a function
            cout << "_________________Mirror Done____________________\n\n";
            break;
        case 'b':
            filterb(); //call filter b function
            cout << "_________________shuffle Done____________________\n\n";
            break;
        case 'c':
            filterc(); //call filter c function
            cout << "_________________Blur Done____________________\n\n";
            break;
        case 's':
            saveImage(); //call save image function
            cout << "_________________Saving File Done____________________\n\n";
            break;
        case '0':
            cout << "Thanks for using our Photoshop\n";
            runner = false; //stop the program runner
            break;

        default:
            cout<<"wrong input Please enter a vaild choice\n";
            break;
        }
    }

    return 0;
}

void loadImage()
{
    char imageFileName[100];
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName; //get the file name from user
    strcat(imageFileName, ".bmp");// Add to it .bmp extension and load image
    readGSBMP(imageFileName, image); //read the file and add it to image array
}

void saveImage()
{
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName; //get the file name from user 
    strcat(imageFileName, ".bmp");// Add to it .bmp extension and load image
    writeGSBMP(imageFileName, image); //write the file from image array
}
//___________________________________________________________
// Ahmed Alaa
void filter1() //Black & White
{
    double avg, sum;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += image[i][j]; //Add the size of each pixel to the sum to help to get avg
        }
    }

    avg = sum / (SIZE * SIZE); //avg will help to know the color is black or white 

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > avg) // if the pixel (image[i][j]) bigger than avg it means the color is white
            {
                image[i][j] = 255;
            }

            else // if the pixel (image[i][j]) smaller than avg it means the color is black
            {
                image[i][j] = 0;
            }
        }
    }
}

//___________________________________________________________
// Ahmed M. Hany
void filter2() //Invert
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j]; //get the pixel color and subtract it from 255
                                            //and assign the value to the image pixel
        }
    }
}
//___________________________________________________________

// Omnia
void filter3() //merge
{
    unsigned char image2[SIZE][SIZE];
    char imageFileName [100];
    cout<<"enter the image 2 file name : ";
    cin >> imageFileName; //get the file name from user
    strcat (imageFileName , ".bmp");
    readGSBMP (imageFileName, image2); //to load the image

    for (int i = 0; i < SIZE; i++) { //row
        for (int j = 0; j< SIZE; j++) { //columns
                int average = 0;
        average =(image [i][j] + image2 [i][j])/2;  //get the average color by get the sum of two pictures pixel color and dividing by 2
        image[i][j]= average;                       // set the new value to image pixel
        }
    }

}
//___________________________________________________________

// Ahmed Alaa
void filter4() //Flip
{
   int x =0;
   char input;//to choosen between Flip (h)orizontally or (v)ertically

   cout<<"Flip (h)orizontally or (v)ertically : ";
   cin>>input;

   if (input == 'v')
   {
    for(int i=0; i < SIZE; i++)
    {
     for(int j=0; j < SIZE/2; j++)
     {

    // to Swap the first pixel with last pixel in the coulmn
        x = image[i][j];
        image[i][j]=image[i][SIZE-1-j];
        image[i][SIZE-1-j]= x;

      }
    }
   }

   else if(input == 'h')
   {

   for(int i=0; i < SIZE/2; i++)
   {
     for(int j=0; j < SIZE; j++)
     {

   // to Swap the first pixel with last pixel in the coulmn 
        x = image[i][j];
        image[i][j]=image[SIZE-1-i][j];
        image[SIZE-1-i][j]= x;
      }
    }
   }
   
   else //to avoid error
   {
     cout<<"unvalid input!";
   }
}
//___________________________________________________________

// Ahmed M. Hany
void filter5() //Rotate
{
    int tmp, deg; //declear variables tmp and deg
    cout << "Please Choose Rotation Degree:\n1-90 degree\n2-180 degree\n3-270 degree\nyour choice: ";
    cin >> deg; //take from user what the degree he want to rotate
    for (int i = 0; i < deg; i++)
    {

        for (int i = 0; i < SIZE / 2; i++) //rows till half
        {
            for (int j = i; j < SIZE - i - 1; j++) //subtract rows from 255
            {
                tmp = image[i][j]; //save the value of image 
                image[i][j] = image[SIZE - j - 1][i]; //get top left side pixel equal bottom left side pixel
                image[SIZE - j - 1][i] = image[SIZE - i - 1][SIZE - j - 1];//get bottom left side pixel equal bottom right side pixel
                image[SIZE - i - 1][SIZE - j - 1] = image[j][SIZE - i - 1];//get bottom right side equal top right side pixel
                image[j][SIZE - i - 1] = tmp;//get right side pixel equal top left side pixel that we save it at tmp
            }
        }
    }
}
//___________________________________________________________

//darken
void darken()
{
  for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
      image[i][j]= image[i][j]/2;  //dividing each pixel color (image[i][j]) by 2
    }
  }
}


// lighten
void lighten()
{
   for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
      int light ;
      light = image[i][j] + (image[i][j]/2); //get 50% of pixel color (image[i][j]/2) + the original pixel color
      if ( light > 255)  //compare it with 255 incase light bigger than 255
      {
        image[i][j] = 255; //then set the color to 255
      }
      else 
      {
        image[i][j] = light ;
      }
    }
  }
}


// Omnia
void filter6 () //darkem and lighten
{
  int choice ;
cout<<"do you want to "<<endl<<" 1-darken" <<endl<<" 2-lighten"<<endl;
cin>>choice;  //to choosen between darker(1) or lighter (2)

if (choice == 1) 
{
  darken();
}
else if (choice == 2)
{
  lighten();
}
else  {
  cout<<"try again ";
}
}
//___________________________________________________________

//ahmed alaa
void filter7(){ //Detect Edges

// nested loops for rows and columns
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      // check if the pixel's value1 - pixel's value2 is bigger than 33 in columns
      // or if the pixel's value1 - pixel's value2 is bigger than 33 in rows
      // * 33 * is the best value to compare in detect edges
      if (abs(image[i][j+1]-image[i][j])>33 || abs(image[i+1][j]-image[i][j])>33){
        image[i][j]=0; //if true make it black to detect edge 
      }
      else{
        image [i][j]=255;// else make it false to detect wallpaper and anything else edges
      }
    
    }
  }
  

}
//___________________________________________________________

//Ahmed M. Hany

unsigned char img2[SIZE][SIZE] ; //declear new imagr aaray
int x=0,y=0;

void copyImage(unsigned char img2[SIZE][SIZE]){ //function to take a copy from the origianl image
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      img2[i][j]=image[i][j];
    }
  }
}

void enlargeFirstQ(){// function for enlarge first Quarter
   for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        image[x][y] = img2[i][j]; //take first pixel and assign it to first pixel in image
        image[x][y+1]= img2[i][j]; //take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1]= img2[i][j];//take last pixel and assign it to last pixel in image
        image[x+1][y]= img2[i][j]; //take dwon pixel and assign it to dawon pixel in image
        y+=2; //counter for the image we want to enlarge by step 2 pixel for columns
      }
      x+=2;//counter for the image we want to enlarge by step 2 pixel for rows
      y=0; //rest columns
    }
}

void enlargeSecondQ(){// function for enlarge second Quarter
  for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        image[x][y] = img2[i][j];//take first pixel and assign it to first pixel in image
        image[x][y+1]= img2[i][j];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1]= img2[i][j]; //take last pixel and assign it to last pixel in image
        image[x+1][y]= img2[i][j]; //take dwon pixel and assign it to dawon pixel in image
        y+=2;//counter for the image we want to enlarge by step 2 pixel for columns
      }
      x+=2;//counter for the image we want to enlarge by step 2 pixel for rows
      y=0;//rest columns
    }
}

void enlargeThirdQ(){// function for enlarge third Quarter
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        image[x][y] = img2[i][j];//take first pixel and assign it to first pixel in image
        image[x][y+1]= img2[i][j];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1]= img2[i][j];//take last pixel and assign it to last pixel in image
        image[x+1][y]= img2[i][j];//take dwon pixel and assign it to dawon pixel in image
        y+=2;//counter for the image we want to enlarge by step 2 pixel for columns
      }
      x+=2;//counter for the image we want to enlarge by step 2 pixel for rows
      y=0;//rest columns
    }
}

void enlargefouthQ(){// function for enlarge fourth Quarter
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        image[x][y] = img2[i][j];//take first pixel and assign it to first pixel in image
        image[x][y+1]= img2[i][j];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1]= img2[i][j];//take last pixel and assign it to last pixel in image
        image[x+1][y]= img2[i][j];//take dwon pixel and assign it to dawon pixel in image
        y+=2;//counter for the image we want to enlarge by step 2 pixel for columns
      }
      x+=2;//counter for the image we want to enlarge by step 2 pixel for rows
      y=0;//rest columns
    }
}

void filter8(){ // Enlarge Image
  int choice;
  
  copyImage(img2); //take a copy of image

  cout<<"choose which quarter you want to enlarge 1 , 2 , 3 or 4: ";
  cin>>choice; //take user input
  if (choice == 1)
  {
   enlargeFirstQ();
  }else if (choice == 2){
    enlargeSecondQ();
  }else if (choice == 3)
  {
    enlargeThirdQ();
  }else if (choice == 4)
  {
    enlargefouthQ();
  }else{
    cout<<"unvalid quarter number , Try again!\n";
  }

}
//___________________________________________________________

//Omnia
// Shrink image
 unsigned char shrinkimage[SIZE][SIZE];
void copyOfImage(unsigned char shrinkimage[SIZE][SIZE])
{
    for (int i = 0 ;i < SIZE ; i++)
    {
        for ( int j = 0 ; j < SIZE ; j++)
        {
            image[i][j]= shrinkimage[i][j];
        }
    }
}


void shrink4()
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            shrinkimage[i/4][j/4] = image[i][j];
        }
    }

}

void shrink2()
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            shrinkimage[i/2][j/2] = image[i][j];
        }
    }

}

void shrink3()
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            shrinkimage[i/3][j/3] = image[i][j];
        }
    }

}

void filter9(){
  int shrink;
  cout<<"do you want to shrink the image to :" <<endl<<"1-shrink 1/2"<<endl<<"2-shrink 1/3"<< endl<<"3-shrink 1/4"<<endl;
  cin>>shrink;
  if (shrink == 1){
      shrink2();
  }
  else if (shrink == 2){
      shrink3();
  }
  else if (shrink == 3){
      shrink4();
  }
  else {
          cout<<"try again";
  }
  copyOfImage(shrinkimage);
}
  
//___________________________________________________________

//Ahmed Alaa

// functions to mirror the user will choose one of them
void mirror_left(){
  // nested loops for row and columns 
  for (int i = 0; i < SIZE; i++)//the row to 256
  {
    for (int j = 0; j < SIZE/2; j++) // coulmns to 128 because we want to mirror the half of the left
    {
      
       image [i][SIZE -j-1] = image [i][j]; //make every pixel in the left half of the picture equal the equivalent to it in the right half of picture 
    }
    
  }

}

void mirror_right(){
  // nested loops for row and columns 
 for (int i = 0; i < SIZE; i++) //the row to 256
  {
  {
    for (int j = 0; j < SIZE/2; j++) // coulmns to 128 because we want to mirror the half of the right
    {
     
      image [i][j] = image [i][SIZE -j-1]; // make every pixel in the right half of the picture equal the equivalent to it in the left half of picture 
    }
    
  }
}
}
void mirror_upper (){
  // nested loops for row and columns
   for (int i = 0; i < SIZE/2; i++) // rows to 128 because we want to mirror the half of the upper
  {
    for (int j = 0; j < SIZE; j++) //the columns to 256
    {
      
       image [SIZE -i-1][j] = image [i][j]; //make every pixel in the bottom half of the picture equal the equivalent to it in the top half of picture  
    }
    
  }
}

void mirror_lower(){
  // nested loops for row and columns
 for (int i = 0; i < SIZE/2; i++) // rows to 128 because we want to mirror the half of the lower
  {
    for (int j = 0; j < SIZE; j++) //the columns to 256
      
       image [i][j] = image [SIZE -i-1][j]; //make every pixel in the top half of the picture equal the equivalent to it in the bottom half of picture  
    {
    }
    
  }

}
void filtera(){ // Mirror image
    int x=0; // the number of mirror will user choose to do
    cout << "1-left1/2\n2-right1/2\n3-upper1/2\n4-lower1/2\nplease choose type of mirror : ";
    cin>>x;

    if(x ==1){
      mirror_left();
    }else  if(x ==2){
      mirror_right();
    }else  if(x ==3){
      mirror_upper();
    }else  if(x ==4){
      mirror_lower();
    }else{
      cout<< "Wrong input";
    }
}

//___________________________________________________________

//Ahmed M. Hany

unsigned char quarterArr[4][128][128] ; // declear quarter array for each quarter

void saveEachQuarter(){ //functon for store every quarter
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
      quarterArr[0][x][y]=image[i][j]; //get pixels of first Quarter into quarter array
      y++;
    }
    x++;
    y=0;
  }
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        quarterArr[1][x][y]=image[i][j];//get pixels of second Quarter into quarter array
        y++;
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        quarterArr[2][x][y]=image[i][j];//get pixels of third Quarter into quarter array
        y++;
      }
      x++;
      y=0;
  }

  x=0,y=0;
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        quarterArr[3][x][y]=image[i][j];//get pixels of fourth Quarter into quarter array
        y++;
      }
      x++;
      y=0;
  }
}
void filterb(){ //shuffle image
  saveEachQuarter(); //call save each quarter function
  int choice[4];
    x=0,y=0;

  cout<<"Enter new order of Quarters: ";
  for (int i = 0; i < 4; i++)
  {
  cin>>choice[i]; //take from user the new order and save them in array
  }

    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        image[i][j] = quarterArr[choice[0]-1][x][y]; //take the first index the user input and add it to first quarter at image
        y++;                                           
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        //take the second index the user input and add it to second quarter at image
        image[i][j] = quarterArr[choice[1]-1][x][y];

        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        //take the third index the user input and add it to third quarter at image
        image[i][j] = quarterArr[choice[2]-1][x][y];
        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        //take the fourth index the user input and add it to fourth quarter at image
        image[i][j] = quarterArr[choice[3]-1][x][y];
        y++;
      }
      x++;
      y=0;
    }
}

//___________________________________________________________


//omnia
//Blur

unsigned char m[3][3];

void part(int k,int f){
  int sum=0;
    for (int i =k ; i < k+3 ; i++){
      for ( int j = f ; j < f+3 ; j++){
        m[i-k][j-f]=image[i][j];
        sum += image[i][j];
      }
  }
  sum = sum/9;
  m[1][1]=sum;
  for (int i =k ; i < k+3 ; i++){
      for ( int j = f ; j < f+3 ; j++){
        image[i][j]=m[i-k][j-f];
      }
  }
}

void filterc(){

  for (int v = 0; v < 2; v++)
  {
    for (int i =0 ; i < SIZE ; i++){
        for ( int j = 0 ; j < SIZE ; j++){
          part(i,j);
        }
    }
  }
}
  

