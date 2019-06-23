// Wynand Tredoux
// June 22 2019

//includes
#include <iostream>
#include <fstream>
#include <string>

//namespace
using namespace std;

void main(int argc, char* argv[]) {
	// Check the number of parameters
	if (argc < 2) {
		// Tell the user how to run the program
		cerr << "Usage: " << argv[0] << " filename" << std::endl;
		return;
	}
	//const char* argvtmp = "test\\Small_Targets.ptx";
	string filelocation = string(argv[1]);
	cout << filelocation << endl;

	//seperate filepath from filename
	string filename;
	string filepath;
	size_t i = filelocation.rfind('\\', filelocation.length());
	if (i != string::npos) {
		filename = (filelocation.substr(i + 1, filelocation.length() - i));
		filepath = (filelocation.substr(0, i + 1));
	}
	else {
		filename = filelocation;
	}
	cout << "filepath is " << filepath << "\nfilename is " << filename;

	//open infile for reading
	ifstream infile(filelocation, ios::in);
	//check that file has opened
	if (!infile.is_open()) {
		cerr << "Error opening " << filelocation;
		return;
	}

	//open outfile for writing (delets exsisting file with the same name)
	string outfilelocation = filepath + "Reduced_" + filename;
	ofstream outfile(outfilelocation, ios::out);
	//check the file has opened
	if (!outfile.is_open()) {
		cerr << "Error opening " << outfilelocation;
		return;
	}


	string line;
	while (getline(infile, line)) {
		//cout << line << endl;

		//if the line contains an empty point
		if (line == "0 0 0 0") {
			//ingore the line
			continue;
		}
		else {
			//write line to new file
			outfile << line << endl;
		}
	}
}