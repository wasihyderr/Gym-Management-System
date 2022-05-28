#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Date
{
private:

	int subs_id;
	int customer_id;
	int plan_id;

	int day;
	int month;
	int year;
	//int time;

public:

	Date()
	{
		subs_id = 0;
		customer_id = 0;
		plan_id = 0;
		day = 0;
		month = 0;
		year = 0;
	}

	Date(int subs_id, int customer_id, int plan_id, int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;

		this->subs_id = subs_id;
		this->customer_id = customer_id;
		this->plan_id = plan_id;
	}


	void setSubsID(int subs_id)
	{
		this->subs_id = subs_id;
	}
	void setCustomerID(int customer_id)
	{
		this->customer_id = customer_id;
	}
	void setPlanID(int plan_id)
	{
		this->plan_id = plan_id;
	}
	int getSubsID()
	{
		return this->subs_id;
	}
	int getCustomerID()
	{
		return this->customer_id;
	}
	int getPlanID()
	{
		return this->plan_id;
	}

	int getDay()
	{
		return this->day;
	}

	int getMonth()
	{
		return this->month;
	}

	int getYear()
	{
		return this->year;
	}

	void printSubsTime()
	{
		cout << day << "/" << month << "/" << year;
	}

	inline void printSubscriptionsData()
	{
		cout << "Subscription ID: " << subs_id << "\t" << "Date/Time: ";
		printSubsTime();
		cout << "\t";
		cout << "Customer ID: " << customer_id << "\t" << "Plan ID: " << plan_id << "\t";
		cout << endl;
	}
};


class Equipment
{
private:
	int ID;
	string name;
public:
	Equipment()
	{
		ID = 0;
		name = "";
	}
	Equipment(int _ID, string _name)
	{
		ID = _ID;
		name = _name;
	}
	//getters/setters
	void setEquipmentID(int ID)
	{
		this->ID = ID;
	}
	int getEquipmentID()
	{
		return this->ID;
	}

	void setEquipmentName(string name)
	{
		this->name = name;
	}
	string getEquipmentName()
	{
		return this->name;
	}

	inline void printEquipmentData()
	{
		cout << "Equipment ID: " << this->ID << "\t" << "Name: " << this->name << endl;
	}

};

class Trainer
{
private:
	int ID;
	string name;
public:
	Trainer(int ID = 0, string name = "")
	{
		this->ID = ID;
		this->name = name;
	}
	//getters/setters
	void setTrainerID(int ID)
	{
		this->ID = ID;
	}
	int getTrainerID()
	{
		return this->ID;
	}
	void setTrainerName(string name)
	{
		this->name = name;
	}
	string getTrainerName()
	{
		return this->name;
	}

	inline void printTrainerData()
	{
		cout << "Trainer ID: " << "\t" << ID << "\t" << "Trainer Name: " << "\t" << name << "\t" << endl;
	}
};


class Customer
{
private:
	int ID;
	string name;
	string address;
	string phone;
	string email;
public:
	Customer(int _ID = 0, string _name = "No Name", string _address = "Unknown", string _phone = "", string _email = "noname@unknown.com")
	{
		ID = _ID;
		name = _name;
		address = _address;
		phone = _phone;
		email = _email;
	}

	//getters/setters
	void setCustomerID(int ID)
	{
		this->ID = ID;
	}

	int getCustomerID()
	{
		return this->ID;
	}

	void setCustomerName(string name)
	{
		this->name = name;
	}
	string getCustomerName()
	{
		return name;
	}
	//address , phone , email
	void setCustomerAddress(string address)
	{
		this->address = address;
	}
	string getCustomerAddress()
	{
		return this->address;
	}

	void setCustomerPhone(string phone)
	{
		this->phone = phone;
	}
	string getCustomerPhone()
	{
		return this->phone;
	}
	void setCustomerEmail(string email)
	{
		this->email = email;
	}
	string getCustomerEmail()
	{
		return this->email;
	}
	void printCustomer()
	{
		cout << "ID: " << ID << "\t" << "Name: " << name << "\t" << "Address: " << address << "\t" << "Phone: " << phone << "\t" << "Email: " << email << endl;
	}
};

class ExcercisePlan
{
private:
	int ID;
	int trainer_id;
	int equipment_id;
	int duration;

public:
	ExcercisePlan(int _ID = 0, int _trainer_id = 0, int _equipment_id = 0, int _duration = 0)
	{
		ID = _ID;
		trainer_id = _trainer_id;
		equipment_id = _equipment_id;
		duration = _duration;
	}

	//getters/setters
	void setExercisePlanID(int ID)
	{
		this->ID = ID;
	}
	int getExercisePlanID()
	{
		return this->ID;
	}

	void setTrainerID(int trainer_id)
	{
		this->trainer_id = trainer_id;
	}
	int getTrainerID()
	{
		return this->trainer_id;
	}

	void setEquipmentID(int equipment_id)
	{
		this->equipment_id = equipment_id;
	}

	int getEquipmentID()
	{
		return this->equipment_id;
	}

	void setDuraton(int duration)
	{
		this->duration = duration;
	}

	int getDuration()
	{
		return this->duration;
	}

	inline void printExercisePlan()
	{
		cout << "Plan ID: " << ID << "\t" << "Trainer ID: " << trainer_id << "\t" << "Equipment ID: " << equipment_id << "\t" << "Duration: " << duration << "\t" << endl;
	}
};


class Gym
{
private:
	string name;
	Trainer* trainer;   //List of Trainers
	int trainer_no;
	Customer* customer;  //List of Customers
	int customer_no;
	ExcercisePlan* excerciseP; //List of excercise plans
	int plan_no;
	Equipment* equipment;   //List of Equipment
	int equip_no;
	Date* subs;
	int subs_no;
	int customer_record[100];
	int cust_index;
	int equip_record[100];
	int equip_index;
	int trainer_record[100];
	int trainer_index;

public:
	Gym(string _name = "Default Gym")
	{
		name = _name;
		equip_no = 0; trainer_no = 0; plan_no = 0; customer_no = 0;
		trainer = nullptr; customer = nullptr; equipment = nullptr; excerciseP = nullptr;
	}

	void AddEquipment(Equipment obj)
	{
		if (equip_no == 0) //If there is no equipnment already
		{
			equipment = new Equipment[1];
			equipment[0].setEquipmentID(obj.getEquipmentID());
			equipment[0].setEquipmentName(obj.getEquipmentName());
			equip_no++;
		}
		else
		{
			//Updating Size and copying previous and new equip into dummy
			Equipment* dummy = new Equipment[equip_no + 1];
			for (int i = 0; i < equip_no; i++)
			{
				dummy[i].setEquipmentID(equipment[i].getEquipmentID());
				dummy[i].setEquipmentName(equipment[i].getEquipmentName());
			}
			dummy[equip_no] = obj;

			//Delete Original and Update with Dummy
			if (equip_no == 1)
			{
				delete[] equipment; equipment = nullptr;
			}
			else
			{
				delete[] equipment; equipment = nullptr;
			}

			equipment = new Equipment[equip_no + 1];

			for (int i = 0; i < equip_no + 1; i++)
			{
				equipment[i].setEquipmentID(dummy[i].getEquipmentID());
				equipment[i].setEquipmentName(dummy[i].getEquipmentName());
			}

			equip_no++;
			//delete dummy
			delete[] dummy; dummy = nullptr;
		}
	}

	void AddCustomer(Customer obj)
	{
		if (customer_no == 0) //If there is no Customer already
		{
			customer = new Customer[1];
			customer[0].setCustomerID(obj.getCustomerID());
			customer[0].setCustomerName(obj.getCustomerName());
			customer[0].setCustomerAddress(obj.getCustomerAddress());
			customer[0].setCustomerPhone(obj.getCustomerPhone());
			customer[0].setCustomerEmail(obj.getCustomerEmail());
			customer_no++;
		}
		else
		{
			//Updating Size and copying previous and new equip into dummy
			Customer* dummy = new Customer[customer_no + 1];
			for (int i = 0; i < customer_no; i++)
			{
				dummy[i].setCustomerID(customer[i].getCustomerID());
				dummy[i].setCustomerName(customer[i].getCustomerName());
				dummy[i].setCustomerAddress(customer[i].getCustomerAddress());
				dummy[i].setCustomerPhone(customer[i].getCustomerPhone());
				dummy[i].setCustomerEmail(customer[i].getCustomerEmail());

			}
			dummy[customer_no] = obj;

			//Delete Original and Update with Dummy
			if (customer_no == 1)
			{
				delete[] customer; customer = nullptr;
			}
			else
			{
				delete[] customer; customer = nullptr;
			}

			customer = new Customer[customer_no + 1];

			for (int i = 0; i < customer_no + 1; i++)
			{
				customer[i].setCustomerID(dummy[i].getCustomerID());
				customer[i].setCustomerName(dummy[i].getCustomerName());
				customer[i].setCustomerAddress(dummy[i].getCustomerAddress());
				customer[i].setCustomerPhone(dummy[i].getCustomerPhone());
				customer[i].setCustomerEmail(dummy[i].getCustomerEmail());
			}

			customer_no++;
			//delete dummy
			delete[] dummy; dummy = nullptr;
		}
	}

	void AddTrainer(Trainer obj)
	{
		if (trainer_no == 0) //If there is no trainer already
		{
			trainer = new Trainer[1];
			trainer[0].setTrainerID(obj.getTrainerID());
			trainer[0].setTrainerName(obj.getTrainerName());
			trainer_no++;
		}
		else
		{
			//Updating Size and copying previous and new trainer into dummy
			Trainer* dummy = new Trainer[trainer_no + 1];
			for (int i = 0; i < trainer_no; i++)
			{
				dummy[i].setTrainerID(trainer[i].getTrainerID());
				dummy[i].setTrainerName(trainer[i].getTrainerName());
			}
			dummy[trainer_no] = obj;

			//Delete Original and Update with Dummy
			if (trainer_no == 1)
			{
				delete[] trainer; trainer = nullptr;
			}
			else
			{
				delete[] trainer; trainer = nullptr;
			}

			trainer = new Trainer[trainer_no + 1];

			for (int i = 0; i < trainer_no + 1; i++)
			{
				trainer[i].setTrainerID(dummy[i].getTrainerID());
				trainer[i].setTrainerName(dummy[i].getTrainerName());
			}

			trainer_no++;
			//delete dummy
			delete[] dummy; dummy = nullptr;
		}
	}

	void CreateExcercisePlan(ExcercisePlan obj)
	{
		if (plan_no == 0) //If there is no Plan already
		{
			excerciseP = new ExcercisePlan(obj);
			plan_no++;
		}
		else
		{
			//Updating Size and copying previous and new trainer into dummy
			ExcercisePlan* dummy = new ExcercisePlan[plan_no + 1];
			for (int i = 0; i < plan_no; i++)
			{
				dummy[i] = excerciseP[i];
			}
			dummy[plan_no] = obj;

			//Delete Original and Update with Dummy
			if (plan_no == 1)
			{
				delete excerciseP; excerciseP = nullptr;
			}
			else
			{
				delete[] excerciseP; excerciseP = nullptr;
			}

			excerciseP = new ExcercisePlan[plan_no + 1];

			for (int i = 0; i < plan_no + 1; i++)
			{
				excerciseP[i] = dummy[i];
			}

			plan_no++;
			//delete dummy
			delete[] dummy; dummy = nullptr;
		}
	}

	bool allowCustomer(Customer obj)    //To check whether customer has Unique ID
	{
		if (cust_index == 0)
		{
			for (int i = 0; i < 100; i++) //MINOR CHANGE MADE HERE
			{
				customer_record[i] = -1;
			}
			customer_record[cust_index] = obj.getCustomerID();
			cust_index++;
			return true;
		}
		else
		{
			for (int i = 0; i < customer_no; i++)
			{
				if (customer_record[i] == obj.getCustomerID())
				{
					return false;
				}
			}
		}
		customer_record[cust_index] = obj.getCustomerID();
		cust_index++;
		return true;
	}

	bool allowEquipment(Equipment obj)    //To check whether Equipment has Unique ID
	{
		if (equip_index == 0)
		{
			for (int i = 0; i < 100; i++) //MINOR CHANGE MADE HERE
			{
				equip_record[i] = -1;
			}
			equip_record[equip_index] = obj.getEquipmentID();
			equip_index++;
			return true;
		}
		else
		{
			for (int i = 0; i < equip_no; i++)
			{
				if (equip_record[i] == obj.getEquipmentID())
				{
					return false;
				}
			}
		}
		equip_record[equip_index] = obj.getEquipmentID();
		equip_index++;
		return true;
	}

	bool allowTrainer(Trainer obj)    //To check whether Trainerhas Unique ID
	{
		if (trainer_index == 0)
		{
			for (int i = 0; i < 100; i++) //MINOR CHANGE MADE HERE
			{
				trainer_record[i] = -1;
			}

			trainer_record[trainer_index] = obj.getTrainerID();
			trainer_index++;
			return true;
		}
		else
		{
			for (int i = 0; i < trainer_no; i++)
			{
				if (trainer_record[i] == obj.getTrainerID())
				{
					return false;
				}
			}
		}
		trainer_record[trainer_index] = obj.getTrainerID();
		trainer_index++;
		return true;
	}

	bool allowSubscription()  //Allow Creation of Subcriptions or not
	{
		if (equip_no == 0 || customer_no == 0 || trainer_no == 0 || plan_no == 0)
		{
			return false;
		}
		else
			return true;
	}

	void AddSubscriptions(Date obj)
	{
		if (subs_no == 0)
		{
			subs = new Date(obj);
			subs_no++;
		}
		else
		{
			//Updating Size and copying previous and new equip into dummy
			Date* dummy = new Date[subs_no + 1];
			for (int i = 0; i < subs_no; i++)
			{
				dummy[i] = subs[i];
			}
			dummy[subs_no] = obj;

			//Delete Original and Update with Dummy
			if (subs_no == 1)
			{
				delete subs; subs = nullptr;
			}
			else
			{
				delete[] subs; subs = nullptr;
			}

			subs = new Date[subs_no + 1];

			for (int i = 0; i < subs_no + 1; i++)
			{
				subs[i] = dummy[i];
			}

			subs_no++;
			//delete dummy
			delete[] dummy; dummy = nullptr;
		}

	}

	bool allowExcercisePlan()  //Allow Creation of ExcercisePlan or not
	{
		if (equip_no == 0 || customer_no == 0 || trainer_no == 0)
		{
			return false;
		}
		else
			return true;
	}

	void printEquipment()
	{
		if (equip_no == 0)
			cout << "There is no equipment." << endl;
		else
		{
			for (int i = 0; i < equip_no; i++)
			{
				equipment[i].printEquipmentData();
			}
			cout << endl;
		}
	}
	void printCustomer()
	{
		if (customer_no == 0)
			cout << "There are no Customers." << endl;
		else
		{
			for (int i = 0; i < customer_no; i++)
			{
				customer[i].printCustomer();
			}
			cout << endl;
		}
	}

	void printTrainers()
	{
		if (trainer_no == 0)
		{
			cout << "There are no trainers available." << endl;
		}
		else
		{
			for (int i = 0; i < trainer_no; i++)
			{
				trainer[i].printTrainerData();
			}
			cout << endl;
		}
	}

	void printExcercisePlans()
	{
		if (plan_no == 0)
		{
			cout << " There are no exercise plans made yet." << endl;
		}
		else
		{
			for (int i = 0; i < plan_no; i++)
			{
				excerciseP[i].printExercisePlan();
			}
			cout << endl;
		}
	}

	void printSubscriptions()
	{
		if (subs_no == 0)
		{
			cout << "There are no subscriptions." << endl;
		}
		else
		{
			for (int i = 0; i < subs_no; i++)
			{
				subs[i].printSubscriptionsData();
			}
			cout << endl;
		}
	}

	void ExportEquipments()
	{
		ofstream Save;
		Save.open("equipments.txt");
		Save << "Equipment ID" << "\t" << "Name" << endl << endl;

		for (int i = 0; i < equip_no; i++)
		{
			Save << equipment[i].getEquipmentID() << "\t  \t  \t  \t" << equipment[i].getEquipmentName() << endl;
		}

		Save.close();

		cout << "Exported to TXT Successfully " << endl;
	}

	void ExportTrainers()
	{
		ofstream Save1;
		Save1.open("trainers.txt");
		Save1 << "Trainer ID" << "\t \t" << "Name" << endl << endl;

		for (int i = 0; i < trainer_no; i++)
		{
			Save1 << trainer[i].getTrainerID() << "\t  \t  \t \t" << trainer[i].getTrainerName() << endl;
		}
		Save1.close();

		cout << "Exported to TXT Successfully " << endl;
	}

	void ExportCustomers()
	{
		ofstream Save2;
		Save2.open("customers.txt");
		Save2 << "Customer ID" << "\t \t" << "Name" << "\t \t \t \t" << "Address" << "\t \t \t \t" << "Phone" << "\t \t \t \t" << "Email" << endl << endl;

		for (int i = 0; i < customer_no; i++)
		{
			Save2 << customer[i].getCustomerID() << "\t \t \t \t" << customer[i].getCustomerName() << "\t \t \t \t" << customer[i].getCustomerAddress() << "\t \t \t \t" << customer[i].getCustomerPhone() << "\t \t \t \t" << customer[i].getCustomerEmail() << endl;
		}

		Save2.close();

		cout << "Exported to TXT Successfully " << endl;
	}

	void ExportExcercisePlans()
	{
		ofstream Save3;
		Save3.open("excerciseplans.txt");
		Save3 << "Plan ID" << "\t" << "Trainer ID" << "\t" << "Equipment ID" << "\t" << "Duration" << endl << endl;

		for (int i = 0; i < plan_no; i++)
		{
			Save3 << excerciseP[i].getExercisePlanID() << "\t \t \t \t" << excerciseP[i].getTrainerID() << "\t \t \t \t" << excerciseP[i].getEquipmentID() << "\t \t \t \t" << excerciseP[i].getDuration() << "\t \t \t \t" << endl;
		}

		Save3.close();

		cout << "Exported to TXT Successfully " << endl;
	}

	void ExportSubscriptions()
	{
		ofstream Save4;
		Save4.open("subscriptions.txt");
		Save4 << "Subscription ID" << "\t \t" << "Date/Time" << "\t" << "Customer ID" << "\t \t" << "Plan ID" << endl << endl;


		for (int i = 0; i < subs_no; i++)
		{
			Save4 << subs[i].getSubsID() << "\t \t \t \t";
			Save4 << subs[i].getDay() << "/" << subs[i].getMonth() << "/" << subs[i].getYear();
			Save4 << "\t \t \t" << subs[i].getCustomerID() << "\t \t \t \t" << subs[i].getPlanID() << endl;
		}

		Save4.close();

		cout << "Exported to TXT Successfully" << endl;

	}

	void DeleteEquipment(int id)
	{
		if (equip_no == 0)
		{
			cout << "There is nothing to Delete. No Equipment." << endl;
			return;
		}
		else
		{
			for (int i = 0; i < equip_no; i++)
			{
				if (equipment[i].getEquipmentID() == id)
				{
					if (equip_no == 1)
					{
						delete[] equipment; equipment = nullptr;
						equip_no--;
						equip_index--;
					}
					else
					{
						//Removing from equip_record by just setting del id to -1
						for (int t = 0; t < equip_index; t++)
						{
							if (equip_record[t] == id)
							{
								equip_record[t] = -1;
							}
						}

						//Remake equipment array with updated stuff
						equip_no--;
						equipment[i].setEquipmentID(-1);  //Marking deleting equipment id as -1
						Equipment* dummy = new Equipment[equip_no + 1];

						for (int j = 0, index = 0; j < equip_no + 1; j++, index++)
						{
							if (equipment[j].getEquipmentID() == -1)
							{
								index--;
								//continue;
							}
							else
							{
								dummy[index].setEquipmentID(equipment[j].getEquipmentID());
								dummy[index].setEquipmentName(equipment[j].getEquipmentName());
							}
						}
						delete[] equipment; equipment = nullptr;
						equipment = new Equipment[equip_no];
						for (int k = 0; k < equip_no; k++)
						{
							equipment[k].setEquipmentID(dummy[k].getEquipmentID());
							equipment[k].setEquipmentName(dummy[k].getEquipmentName());
						}
						delete[] dummy; dummy = nullptr;
					}
				}
			}
		}
	}

	void DeleteCustomer(int id)
	{
		if (customer_no == 0)
		{
			cout << "There is nothing to Delete. No Customers." << endl;
			return;
		}
		else
		{
			for (int i = 0; i < customer_no; i++)
			{
				if (customer[i].getCustomerID() == id)
				{
					if (customer_no == 1)
					{
						delete[] customer; customer = nullptr;
						customer_no--;
						cust_index--;
					}
					else
					{
						//Removing from equip_record by just setting del id to -1
						for (int t = 0; t < cust_index; t++)
						{
							if (customer_record[t] == id)
							{
								customer_record[t] = -1;
							}
						}

						//Remake equipment array with updated stuff
						customer_no--;
						customer[i].setCustomerID(-1);  //Marking deleting equipment id as -1
						Customer* dummy = new Customer[customer_no + 1];

						for (int j = 0, index = 0; j < customer_no + 1; j++, index++)
						{
							if (customer[j].getCustomerID() == -1)
							{
								index--;
								//continue;
							}
							else
							{
								dummy[index].setCustomerID(customer[j].getCustomerID());
								dummy[index].setCustomerName(customer[j].getCustomerName());
							}
						}
						delete[] customer; customer = nullptr;
						customer = new Customer[customer_no];
						for (int k = 0; k < customer_no; k++)
						{
							customer[k].setCustomerID(dummy[k].getCustomerID());
							customer[k].setCustomerName(dummy[k].getCustomerName());
						}
						delete[] dummy; dummy = nullptr;
					}
				}
			}
		}
	}

	void DeleteTrainer(int id)
	{
		if (trainer_no == 0)
		{
			cout << "There is nothing to Delete. No Trainers." << endl;
			return;
		}
		else
		{
			for (int i = 0; i < trainer_no; i++)
			{
				if (trainer[i].getTrainerID() == id)
				{
					if (trainer_no == 1)
					{
						delete[] trainer; trainer = nullptr;
						trainer_no--;
						trainer_index--;
					}
					else
					{
						//Removing from equip_record by just setting del id to -1
						for (int t = 0; t < trainer_index; t++)
						{
							if (trainer_record[t] == id)
							{
								trainer_record[t] = -1;
							}
						}

						//Remake equipment array with updated stuff
						trainer_no--;
						trainer[i].setTrainerID(-1);  //Marking deleting equipment id as -1
						Trainer* dummy = new Trainer[trainer_no + 1];

						for (int j = 0, index = 0; j < trainer_no + 1; j++, index++)
						{
							if (trainer[j].getTrainerID() == -1)
							{
								index--;
								//continue;
							}
							else
							{
								dummy[index].setTrainerID(trainer[j].getTrainerID());
								dummy[index].setTrainerName(trainer[j].getTrainerName());
							}
						}
						delete[] trainer; trainer = nullptr;
						trainer = new Trainer[trainer_no];
						for (int k = 0; k < trainer_no; k++)
						{
							trainer[k].setTrainerID(dummy[k].getTrainerID());
							trainer[k].setTrainerName(dummy[k].getTrainerName());
						}
						delete[] dummy; dummy = nullptr;
					}
				}
			}
		}
	}

};


void creator_menu(Gym Our_Gym)
{
	int decision = -1;
	while (decision != 0)
	{
		cout << "\t" << "1 - Add Equipment" << endl;
		cout << "\t" << "2 - Add Customer" << endl;
		cout << "\t" << "3 - Add Trainer" << endl;
		cout << "\t" << "4 - Add Subscriptions" << endl;
		cout << "\t" << "5 - Create Excercise Plan" << endl;
		cout << "\t" << "6 - Display all Equipment" << endl;
		cout << "\t" << "7 - Display all Customer" << endl;
		cout << "\t" << "8 - Display all Trainers" << endl;
		cout << "\t" << "9 - Display all Subscriptions" << endl;
		cout << "\t" << "10 - Display all Excercise Plan" << endl;
		cout << "\t" << "11 - Print Equipment to TXT File." << endl;
		cout << "\t" << "12 - Print Trainers to TXT File." << endl;
		cout << "\t" << "13 - Print Customers to TXT File." << endl;
		cout << "\t" << "14 - Print ExcercisePlans to TXT File." << endl;
		cout << "\t" << "15 - Print Subscriptions to TXT File." << endl;
		cout << "\t" << "16 - Delete an Equipment." << endl;
		cout << "\t" << "17 - Delete a Customer." << endl;
		cout << "\t" << "18 - Delete a Trainer." << endl;
		cout << "\t" << "0 - Exit" << endl;

		cout << "Decision: ";
		cin >> decision; cout << endl;

		if (decision == 1)
		{
			int id;
			string naam;
			cout << "Equipment ID: ";
			cin >> id;
			cin.ignore();
			cout << endl;
			cout << "Equipment Name: ";
			getline(cin, naam);
			cout << endl;

			Equipment dummy(id, naam);
			if (Our_Gym.allowEquipment(dummy))
			{
				Our_Gym.AddEquipment(dummy);
			}
			else
			{
				cout << "Entry not made. ID already taken. Use another ID." << endl;
			}

			cout << endl;
		}

		else if (decision == 2)
		{
			int id1;
			string name1, address1, phone1, email1;
			cout << "Customer ID: " << endl;
			cin >> id1;
			cin.ignore();
			cout << "Customer Name: " << endl;
			getline(cin, name1);
			cout << "Customer Address: " << endl;
			getline(cin, address1);
			cout << "Customer PhoneNumber: " << endl;
			getline(cin, phone1);
			cout << "Customer Email: " << endl;
			getline(cin, email1); cout << endl;

			Customer dummy1(id1, name1, address1, phone1, email1);
			if (Our_Gym.allowCustomer(dummy1))
			{
				Our_Gym.AddCustomer(dummy1);
			}
			else
			{
				cout << "Entry not made. ID already taken. Use another ID." << endl;
			}
			cout << endl;
		}

		else if (decision == 3)
		{
			int id2;
			string name2;

			cout << "Trainer ID: " << endl;
			cin >> id2;
			cin.ignore();
			cout << "Trainer Name: " << endl;
			getline(cin, name2);

			Trainer dummy2(id2, name2);
			if (Our_Gym.allowTrainer(dummy2))
			{
				Our_Gym.AddTrainer(dummy2);
			}
			else
			{
				cout << "Entry not made. ID already taken. Use another ID." << endl;
			}
			cout << endl;
		}

		else if (decision == 4)
		{
			if (Our_Gym.allowSubscription())
			{
				int subs_id, customer_id, plan_id, day, month, year;
				cout << "Todays Date: " << endl;
				cout << "DD: ";
				cin >> day;
				while (day <= 0 && day > 31)
				{
					cout << "Invalid input. Try again." << endl;
					cin >> day;
				}
				cout << "MM: ";
				cin >> month;
				while (month <= 0 && month > 12)
				{
					cout << "Invalid input. Try again." << endl;
					cin >> month;
				}
				cout << "YYYY: ";
				cin >> year;
				while (year <= 0)
				{
					cout << "Invalid input. Try again." << endl;
					cin >> year;
				}
				cout << day << "/" << month << "/" << year;

				cout << endl;

				cout << "Subscription ID: ";
				cin >> subs_id;
				cout << endl;
				cout << "Customer ID: ";
				cin >> customer_id;
				cout << endl;
				cout << "Plan ID: ";
				cin >> plan_id;

				Date dummy3(subs_id, plan_id, customer_id, day, month, year);
				Our_Gym.AddSubscriptions(dummy3);
				//cout << endl;
			}
			else
			{
				cout << "Not enough Data to create subscriptions." << endl << endl;
			}
		}
		else if (decision == 5)
		{
			if (Our_Gym.allowExcercisePlan())
			{
				int plan_id; int trainer_id; int equipment_id; int duration;
				cout << "Plan ID: ";
				cin >> plan_id; cout << endl;
				cout << "Trainer ID: ";
				cin >> trainer_id; cout << endl;
				cout << "Equipment ID: ";
				cin >> equipment_id; cout << endl;
				cout << "Duration: ";
				cin >> duration; cout << endl;

				ExcercisePlan dummy(plan_id, trainer_id, equipment_id, duration);
				Our_Gym.CreateExcercisePlan(dummy);
				cout << endl;
			}
			else
				cout << "Not enough Data to create Excercise Plan." << endl << endl;
		}
		else if (decision == 6)
		{
			Our_Gym.printEquipment();
			cout << endl;
		}
		else if (decision == 7)
		{
			Our_Gym.printCustomer();
			cout << endl;
		}
		else if (decision == 8)
		{
			Our_Gym.printTrainers();
			cout << endl;
		}
		else if (decision == 9)
		{
			Our_Gym.printSubscriptions();
			cout << endl;
		}
		else if (decision == 10)
		{
			Our_Gym.printExcercisePlans();
			cout << endl;
		}
		else if (decision == 11)
		{
			Our_Gym.ExportEquipments();
			cout << endl;
		}
		else if (decision == 12)
		{
			Our_Gym.ExportTrainers();
			cout << endl;
		}
		else if (decision == 13)
		{
			Our_Gym.ExportCustomers();
			cout << endl;
		}
		else if (decision == 14)
		{
			Our_Gym.ExportExcercisePlans();
			cout << endl;
		}
		else if (decision == 15)
		{
			Our_Gym.ExportSubscriptions();
			cout << endl;
		}
		else if (decision == 16)
		{
			int d;
			cout << "ID of Equipment you wish to delete: ";
			cin >> d; cout << endl;

			Our_Gym.DeleteEquipment(d);
		}
		else if (decision == 17)
		{
			int d;
			cout << "ID of Customer you wish to delete: ";
			cin >> d; cout << endl;

			Our_Gym.DeleteCustomer(d);
		}

		else if (decision == 18)
		{
			int d;
			cout << "ID of Trainer you wish to delete: ";
			cin >> d; cout << endl;

			Our_Gym.DeleteTrainer(d);
		}

	}
}

void menu()
{
	cout << "\t" << ".:: Welcome to Gym Manager Database ::." << endl << endl;
	cout << "\t" << "1 - Create a Gym." << endl;
	cout << "\t" << "2 - Exit." << endl << endl;
	int decision;
	cout << "\t" << "Enter Decision: ";
	cin >> decision; cout << endl;

	string gym_name;
	if (decision == 2)
	{
		return;
	}
	else if (decision == 1)
	{
		cout << "Please Enter your desired Gym Name: ";
		cin >> gym_name;
		cout << endl;
		//Creating Gym Object with given name
		Gym Our_Gym(gym_name);

		creator_menu(Our_Gym);
	}
}

int main()
{
	menu();
}