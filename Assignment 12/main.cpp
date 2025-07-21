#include <iostream>
#include <fstream>
#include <sstream> // string stream operations to parse CSV
#include <vector> // vector to store weather entries
using namespace std;

class WeatherEntry {
public:
	string location;
	string date;
	double temp;
	double humidity;
	double windSpeed;

	// constructor takes a single line from the CSV file
	WeatherEntry(string line) {
		stringstream ss(line); // split the line into parts
		string token; // temporary string to hold each part

		getline(ss, location, ',');
		getline(ss, date, ',');

		getline(ss, token, ',');
		temp = stod(token);

		getline(ss, token, ',');
		humidity = stod(token);

		getline(ss, token, ',');
		windSpeed = stod(token);
	}

	// print function 
	void print() const {
		cout<<"Location: "<<location<<", Date: "<<date
			<< ", Temp: " << temp << "C, Humidity: " << humidity << "%, Wind Speed: " << windSpeed << " km/h" << endl;
	}
};

// read the CSV file and create WeatherEntry objects
int main() {
	ifstream file("weather_data.csv");
	if (!file.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	string line; // holds each line from the file
	vector<WeatherEntry> entries; // stores WeatherEntry objects

	getline(file, line); // skip the header line

	// reads up to 10 entries from the file
	while (getline(file, line) && entries.size() < 10) {
		WeatherEntry entry(line);
		entries.push_back(entry);
	}

	file.close(); 

	// display all loaded entries
	cout << "\nWeather Data Entries:\n";
	for (const auto& entry : entries) {
		entry.print();
	}

	return 0;

}