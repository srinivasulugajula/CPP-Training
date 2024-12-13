#include<bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
	string vecnum;
	string vectype;
	int entry;
	int ext;
public:
	Vehicle(string num, string type) {
		vecnum = num;
		vectype = type;
		entry = time(0);
	}

	string getVehicleNumber() {
		return vecnum;
	}
	string getVehicleType() {
		return vectype;
	}
	int getEntryTime() {
		return entry;
	}
	void setExitTime(int exitTime) {
		ext = exitTime;
	}
	int getExitTime() {
		return ext;
	}
};

class ParkingSystem {
private:
	int parkingbayslots;
	int emergencyslots = 10;
	int count = 0;
	vector<Vehicle*> parking;
	queue<Vehicle*> waitingQueue;
	priority_queue<Vehicle*> emergencyVehicles;
	queue<Vehicle*> normalQueue;
	int waitingsize = 10;
	double totalRevenue = 0;

public:
	ParkingSystem(int slots) {
		parkingbayslots = slots;
		parking.resize(parkingbayslots, nullptr);
	}

	void VehicleEntry(string num, string type) {
		Vehicle* vec1 = new Vehicle(num, type);

		if (type == "E") {
			emergencyVehicles.push(vec1);
		} else {
			normalQueue.push(vec1);
		}
		Parking();
	}

	void Parking() {
		if (count < parkingbayslots) {
			if (!emergencyVehicles.empty()) {
				for (int i = 0; i < parkingbayslots / 4; i++) {
					if (parking[i] == nullptr) {
						Vehicle* vec = emergencyVehicles.top();
						emergencyVehicles.pop();
						parking[i] = vec;
						cout << "Emergency vehicle " << vec->getVehicleNumber() << " parked at : slot " << i << endl;
						count++;
						break;
					}
				}
			}

			if (!normalQueue.empty()) {
				for (int i = parkingbayslots / 4; i < parkingbayslots; i++) {
					if (parking[i] == nullptr) {
						Vehicle* vec = normalQueue.front();
						normalQueue.pop();
						parking[i] = vec;
						cout << "Normal vehicle " << vec->getVehicleNumber() << " parked at : slot " << i << endl;
						count++;
						break;
					}
				}
			}
		} else {
			if (waitingsize != 0) {
				if (!emergencyVehicles.empty()) {
					Vehicle* vec = emergencyVehicles.top();
					emergencyVehicles.pop();
					waitingQueue.push(vec);
					cout << "\nEmergency vehicle " << vec->getVehicleNumber() << " parked in the waiting area" << endl;
					waitingsize--;
				}
			} else {
				cout << "\nNo place for parking and waiting area is full" << endl;
			}
		}
	}
	void waitpush() {
		if(!waitingQueue.empty()) {
			Vehicle *vec=waitingQueue.front();
			waitingQueue.pop();
			for(int i=parkingbayslots/4; i<parkingbayslots; i++) {
				if(parking[i]==nullptr) {
					parking[i]=vec;
					cout << "\nVehicle " << vec->getVehicleNumber() << " parked at : slot " << i << endl;
				}
			}
		}
		else {
			cout<<"No vehicles are in the waiting queue"<<endl;
		}
	}

	void vehicleExit(string vehicleNumber) {
		for (int i = 0; i < parkingbayslots; ++i) {
			if (parking[i] != nullptr && parking[i]->getVehicleNumber() == vehicleNumber) {
				Vehicle* parkedVehicle = parking[i];
				parkedVehicle->setExitTime(time(0));
				totalRevenue += calculateFee(parkedVehicle);
				parking[i] = nullptr;
				cout << "\nVehicle " << vehicleNumber << " exited. Fee: $" << calculateFee(parkedVehicle) << endl;
				break;
			}
		}
		waitpush();
	}

	double calculateFee(Vehicle* vehicle) {
		double feePerHour = 0.0;

		if (vehicle->getVehicleType() == "E") {
			feePerHour = 0.0;
		} else if (vehicle->getVehicleType() == "car") {
			feePerHour = 200.0;
		} else if (vehicle->getVehicleType() == "bike") {
			feePerHour = 100.0;
		}

		double durationInHours = difftime(vehicle->getExitTime(), vehicle->getEntryTime())/10000;
		return feePerHour * durationInHours*10;
	}

	void displaySystemStatus() {
		cout << "Parking Bay Status:\n";
		for (int i = 0; i < parkingbayslots; ++i) {
			if (parking[i] != nullptr) {
				cout << "Spot " << i << ": " << parking[i]->getVehicleType() << " vehicle " << parking[i]->getVehicleNumber() << endl;
			} else {
				cout << "Spot " << i << ": Empty\n";
			}
		}

		cout << "\nWaiting Queue (Normal Vehicles):\n";
		queue<Vehicle*> tempQueue = waitingQueue;
		while (!tempQueue.empty()) {
			cout << (tempQueue.front()->getVehicleType() == "car" ? "Car " : "Bike ") << tempQueue.front()->getVehicleNumber() << "\n";
			tempQueue.pop();
		}

		cout << "\nTotal Revenue: $" << totalRevenue << endl;
	}

	~ParkingSystem() {
		cout<<"________________________________________"<<endl;
		cout<<"Total Revenue Genarated:$"<<totalRevenue<<endl;
		cout<<"________________________________________"<<endl;
	}

};

int main() {
	ParkingSystem p(10);
	p.VehicleEntry("TS12003", "bike");

	p.VehicleEntry("AP2103", "E");
	p.displaySystemStatus();
	this_thread::sleep_for(chrono::seconds(2));
	p.vehicleExit("AP2103");
	p.VehicleEntry("AP12222","car");
	p.VehicleEntry("TS12333","E");
	this_thread::sleep_for(chrono::seconds(5));
	p.vehicleExit("TS12003");
	p.vehicleExit("TS12333");
	p.vehicleExit("AP12222");

}
