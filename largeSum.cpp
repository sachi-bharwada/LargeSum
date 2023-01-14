#include <iostream>//Include iostream library
#include <cstring>// required for string manipulation
using namespace std;//Declare use of namespace

int main(const int argc, const char* argv[]) {
    int count = 0;//Define memory space for integer count value and declare count value to 0
    int tempSum;//Define memory space for integer tempSum value

    
    const int size1 = strlen(argv[1]);//Check length of argv[1]
    const int size2 = strlen(argv[2]);//Check length of argv[2]
    int numberOne[size1];// Define and declare numberOne
    int numberTwo[size2];// Define and declare numberTwo

    //Use input from command line arguments to form numberOne, 
    //and using ASCII table, turn into correct integer values
    for (int a = 0; a < size1; a++){
        numberOne[a] = int(argv[1][a]) - 48;
    }
    //Use input from command line arguments to form numberTwo, 
    //and using ASCII table, turn into correct integer values
    for (int a = 0; a < size2; a++){
        numberTwo[a] = int(argv[2][a]) - 48;
    }

    //Define another integer numberThree in the case that carrying over needs to occur
    const int size3 = max(size1, size2) + 1;
    int numberThree[size3];

    for (int a = 0; a < size3; a++){//Iterate to make numberThree have zeroes only
        numberThree[a] = 0;
    }
 

    while (count + 1 <= size1 && count + 1 <= size2){//While both inputs have numbers 
        tempSum = numberOne[size1 - count - 1] + numberTwo[size2 - count - 1];//Use the tempSum variable to calculate a temporary value
        if (tempSum + numberThree[size3 - count - 1] >= 10){//Check if the sum is greater than or equal to 10, if so, then substitute 10 and carry over 1 
            numberThree[size3 - count - 2] += 1;
            numberThree[size3 - count - 1] += tempSum - 10;
        } 
        else{//If sum is < 10, then the place value for numberThree should equal tempSum  
            numberThree[size3 - count - 1] += tempSum;
        }
        count++;//Add count by 1
    }
 
    while (count + 1 <= size2){//While the second number has remaining digits
        tempSum = numberTwo[size2 - count - 1];//Use the tempSum variable to calculate a temporary value
        if (tempSum + numberThree[size3 - count - 1] >= 10){//Check if the sum is greater than or equal to 10, if so, then substitute 10 and carry over 1 
            numberThree[size3 - count - 2] += 1;
            numberThree[size3 - count - 1] += tempSum - 10;
        } 
        else{//If sum is < 10, then the place value for numberThree should equal tempSum
            numberThree[size3 - count - 1] += tempSum;
        }
        count++;//Add count by 1
    }
    while (count + 1 <= size1){//While the first number has remaining digits
        tempSum = numberOne[size1 - count - 1];//Use the tempSum variable to calculate a temporary value
        if (tempSum + numberThree[size3 - count - 1] >= 10){//Check if the sum is greater than or equal to 10, if so, then substitute 10 and carry over 1 
            numberThree[size3 - count - 2] += 1;
            numberThree[size3 - count - 1] += tempSum - 10;
        } 
        else{//If sum is < 10, then the place value for numberThree should equal tempSum
            numberThree[size3 - count - 1] += tempSum;
        }
        count++;//Add count by 1
    }

    //Show onscreen the sum
    cout << "Sum: ";

    //Check if the 1st digit of the array is equal to 1 or 0 and follow the steps accordingly
    if (!numberThree[0]){
        for (int a = 1; a < size3; a++){
            cout << numberThree[a];//Output the numberThree as the sum
        } 
    }
    else{
        for (int a = 0; a < size3; a++){
            cout << numberThree[a];//Output the numberThree as the sum
        }
        return 0;
    }

}
