#include<string>
#include<iostream>
using namespace std;

class VectorInFile
{
	string name;
	static const int width = 10;
	FILE* fWrite, *fRead;
public:
	VectorInFile(string name)
	{
		this->name=name;
	}
	void StartWriting()
	{
		fWrite = fopen(name.c_str(), "w");
	}
	void write(int element)
	{
		fprintf(fWrite, "%10d", element);
	}
	void EndWriting()
	{
		fclose(fWrite);
	}

	void StartReading()
	{
		fRead = fopen(name.c_str(), "r");
	}
	int read(int i)
	{
		fseek (fRead , width*i, SEEK_SET );
		int ans;
		fscanf(fRead, "%d", &ans);
		return ans;
	}
	void EndReading()
	{
		fclose(fRead);
	}
};