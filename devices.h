#ifndef DEVICES_H
#define DEVICES_H

class malfunctionRecord {

private:
	int mlfn_count;
	int mlfn_type;
	int mlfn_time;

public:
	malfunctionRecord();
	void malfunction(int mlfn, int tm);
	void display();
	int getRecord(int *m, int *t);
};


class device {

private:
	char* device_name;
	malfunctionRecord malf;
	int serial_number;
	int device_value;

public:
	device(char* n, int sn);
	~device();
	void display();
	void recordMalfunction(int m, int t);
	int getMalfunctionRecord(int *m, int *t);
	int amIThisDevice(char *n);
};

#endif