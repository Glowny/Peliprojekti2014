#pragma once
#include <vector>;
using namespace std;
class vihu
{

public:
	vihu(float x,float y, int vA);
	~vihu(void);
	void movement(float followX, float followY, int peliAika);
	float giveX();
	float giveY();

	void vihu::setY(float xs);
	void vihu::setX(float xs);
private:
	float vihuX;
	float vihuY;
	int vihuAika;
	
};

