#include <iostream>
#include <fstream>
using namespace std;

//#define failureFileName "failures.txt"

// In this example program, we hard code the names of the
// two output files ("passes", "failures"), but we allow the
// user to specify the name of the input file on the command
// line (passed in as argv[1])
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Please provide the file name." << endl;
        return 1;
    }

    // Okay, argc > 1, we have input! Let's call it rawGrades
    // C++ will search for the file and find it, and grab it
    ifstream is_rawGrades (argv[1]);
    if (!is_rawGrades) {
        cerr << "Couldn't open the file." << endl;
        return 1;
    }

    // Now we create our output file streams
    // We can create it in many ways
    ofstream os_pass ("passes.txt"); // string literal ✅
    const string failureFileName = "failures.txt";
    ofstream os_fail (failureFileName); // string variable ✅

    // Now we should also check if they are both valid
    if (!(os_fail && os_pass)) {
        cerr << "Couldn't create output files." << endl;
        return 1;
    }

    int grade;
    string name;

    // Use the file streams just like cin and cout
    while (is_rawGrades >> grade >> name) {
        if (grade > 50) {
            os_pass << grade << " " << name << endl;
        }
        else {
            os_fail << grade << " " << name << endl;
        }
    }

    // Closing the file streams is optional since main() does it for us
    is_rawGrades.close();
    os_pass.close();
    os_fail.close();

    // close() does three important things, that makes it only important if we are reusing
    // 1. flushes output buffers (gurantees nothing lost)
    // 2. releases the OS file handle (makes it available to other programs)
    // 3. closes the stream (no longer associated with a file)
}