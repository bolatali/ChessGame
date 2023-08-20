
#include <iostream>
#include <string>
using namespace std;

class ChessElement {
public:
	string element_colour;
	string element_type;
	float element_point;
	int position_x;
	int position_y;


	ChessElement();
	ChessElement(string, string, float, int, int);
	void displayProperty();
	void setvalue(string, string, float, int, int);
	string getType() {
		return element_type;
	}
	string getColour() {
		return element_colour;
	}
	float getPoint() {
		return element_point;
	}



};
void ChessElement::displayProperty()
{
	cout << element_colour << endl;
	cout << element_type << endl;
	cout << element_point << endl;
	cout << "pozisyonu: " << position_x << "," << position_y << endl;
}
void ChessElement::setvalue(string colour, string type, float point, int p_x, int p_y)
{
	element_colour = colour;
	element_type = type;
	element_point = point;
	position_x = p_x;
	position_y = p_y;


}
ChessElement::ChessElement()
{
	element_colour = "none";
	element_type = "none";
	element_point = 0;
	position_x = 0;
	position_y = 0;
}

ChessElement::ChessElement(string colour, string type, float point, int p_x, int p_y)
{
	element_colour = colour;
	element_type = type;
	element_point = point;
	position_x = p_x;
	position_y = p_y;

}

class Horse : public ChessElement {
public:

	void move(vector <ChessElement>& chessElements);

	Horse(string colour, string type, float point, int p_x, int p_y) :ChessElement(colour, type, point, p_x, p_y){}
	
	
	


};
void Horse::move(vector <ChessElement>& chessElements)
{
	
	if (element_colour == "black")
	{
		
		for (int i = 0; i < chessElements.size(); ++i)
		{
			if (chessElements[i].element_colour == "white") //taslarin rengi farkliysa birbirini tehdit edebilir.
			{
				if ((position_x + 1) < 8 && (position_y - 2) > 0)  //Atin olasi tum L seklindeki hareketini kontrol eder.
				{
					
					if (position_x + 1 == chessElements[i].position_x && position_y - 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2; //Atin hareket alaninda karsi renkten bir tas varsa tasin puani yariya iner.
					}
					
				}
				if ((position_x + 2) < 8 && (position_y - 1) > 0) 
				{
					
					if (position_x + 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x + 2) < 8 && (position_y + 1) < 8) 
				{
					
					if (position_x + 2 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x + 1) < 8 && (position_y + 2) > 0) 
				{

					if (position_x + 1 == chessElements[i].position_x && position_y + 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 1) < 8 && (position_y + 2) > 0) 
				{
					
					if (position_x + 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 2) < 8 && (position_y + 1) > 0) 
				{
					
					if (position_x - 2 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 2) < 8 && (position_y - 1) > 0) 
				{

					if (position_x - 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 1) < 8 && (position_y - 2) > 0) 
				{

					if (position_x - 1 == chessElements[i].position_x && position_y - 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
			}
		}
		
	}
	else 
	{
		
		for (int i = 0; i < chessElements.size(); ++i)
		{
			
			if (chessElements[i].element_colour == "black") //taslarin rengi farkliysa birbirini tehdit edebilir.
			{
				if ((position_x + 1) < 8 && (position_y - 2) > 0) //Atin olasi tum L seklindeki hareketini kontrol eder.
				{
					if (position_x + 1 == chessElements[i].position_x && position_y - 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2; //Atin hareket alaninda karsi renkten bir tas varsa tasin puani yariya iner.
						
					}

				}
				if ((position_x + 2) < 8 && (position_y - 1) > 0) {

					if (position_x + 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x + 2) < 8 && (position_y + 1) > 0) {

					if (position_x + 2 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x + 1) < 8 && (position_y + 2) > 0) {

					if (position_x + 1 == chessElements[i].position_x && position_y + 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 1) < 8 && (position_y + 2) > 0) {

					if (position_x + 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 2) < 8 && (position_y + 1) > 0) {

					if (position_x - 2 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 2) < 8 && (position_y - 1) > 0) {

					if (position_x - 2 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
						
					}
				}
				if ((position_x - 1) < 8 && (position_y - 2) > 0) {

					if (position_x - 1 == chessElements[i].position_x && position_y - 2 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2;
					
					}
				}
			}
		}
	}

	
	

}

class Piyon : public ChessElement {
public:

	void move(vector <ChessElement>& chessElements);

	Piyon(string colour, string type, float point, int p_x, int p_y) :ChessElement(colour, type, point, p_x, p_y){}
	
		
	
};

void Piyon::move(vector <ChessElement>& chessElements) 
{ 
	if (element_colour == "black") // siyah taslarin hep üst tarafta beyaz taslarin alt tarafta basladigi varsayilmistir.
	{ // siyah taslar yukardan asagi ilerler
		for (int i = 0; i < chessElements.size(); ++i) 
		{
			if (chessElements[i].element_colour == "white") // taslarin rengi farkli mi diye kontrol edilir.
			{
				
				if ( position_x < 8 && position_y < 8 && position_x > 1 && position_y > 1) //sað ve sol capraz ilerleyebilecek konumdaysa.(piyon sadece [2-7] araligindaki satir ve sutundaysa hem sol hem sag capraz ilerleyebilir.)
				{
					
					if (position_x - 1 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) 
					{
						chessElements[i].element_point /= 2; //piyonun sol asagi hareketinde karsi renkten bir tas var ise o tasin puani yariya duser.

					}
					else if (position_x + 1 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y)
					{
						
						chessElements[i].element_point /= 2; //piyonun sol asagi hareketinde karsi renkten bir tas var ise o tasin puani yariya duser.
						
					}

				}
				else if (position_x == 1 && position_y < 8) {  //en sol sutundaysa piyon sadece sag carpaz ilerler.
					
					if (position_x + 1 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y)
					{
						chessElements[i].element_point /= 2; //piyonun sag capraz asagi hareketinde karsi renkten bir tas var ise o tasin puani yariya duser.
						
					}
				}
				else if (position_x == 8 && position_y < 8) { // en sag sutundaysa piyon sadece sol capraz ilerler

					if (position_x - 1 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_y) {
						chessElements[i].element_point /= 2; //piyonun sol capraz asagi hareketinde karsi renkten bir tas var ise o tasin puani yariya duser.
						
					}
				}
			
			}
		}

		

	}
	else {
		//Beyaz piyon sadece yukari capraz hareket edebilir.
		for (int i = 0; i < chessElements.size(); ++i) 
		{
			if (chessElements[i].element_colour == "black") 
			{
				if ( position_x <8 && position_y < 8 && position_x > 1 && position_y > 1) //sað ve sol capraz ilerleyebilecek konumdaysa.
				{
					if (position_x - 1 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y)
					{
						chessElements[i].element_point /= 2; //piyonun sol yukari capraz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
						

					}
					else if (position_x + 1 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_y)
					{
						chessElements[i].element_point /= 2; //piyonun sag yukari capraz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
						
					}

				}else if (position_x == 1 && position_y < 8) //piyon en sol sutundaysa
				{
					if (position_x + 1 == chessElements[i].position_x && position_y + 1 == chessElements[i].position_x)
					{
						chessElements[i].element_point /= 2; ////piyonun sag yukari capraz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
						
					}
				}
				else if (position_x == 8 && position_y < 8) //piyon en sag sutundaysa
				{
					if (position_x - 1 == chessElements[i].position_x && position_y - 1 == chessElements[i].position_x)
					{
						chessElements[i].element_point /= 2; //piyonun sol yukari capraz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
						
					}
				}

				
			}
		}
			

	}
		
}

class Kale : public ChessElement {
public:

	void move(vector <ChessElement>& chessElements);

	Kale(string colour, string type, float point, int p_x, int p_y) :ChessElement(colour, type, point, p_x, p_y){}
	

};

void Kale::move(vector <ChessElement>& chessElements)
{
	
	if (element_colour == "black")
	{
		for (int i = 0; i < chessElements.size(); ++i)
		{
			
			for (int j = position_y-1; j > 0; --j)
			{
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "black")
				{
					break; //kalenin yukari duz hareketinde kendisiyle ayni renkten bir tas var ise dongu kirilir.
				}
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "white")
				{
					chessElements[i].element_point /= 2; //kalenin yukari duz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
					break;
				}
			}

			for (int j = position_y + 1; j < 8; ++j)
			{
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "black")
				{
					break; //kalenin asagi duz hareketinde kendisiyle ayni renkten bir tas var ise dongu kirilir.
				}
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "white")
				{
					chessElements[i].element_point /= 2; //kalenin asagi duz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
					break;
				}
			}
			
			for (int j = position_x - 1; j > 0; --j)
			{
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "black")
				{
					break; //kalenin sol duz hareketinde kendisiyle ayni renkten bir tas var ise dongu kirilir.
				}
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y &&  chessElements[i].element_colour == "white")
				{
					chessElements[i].element_point /= 2; //kalenin sol duz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
					break;
				}
			}

			for (int j = position_x + 1; j < 8; ++j)
			{
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "black")
				{
					break; //kalenin sag duz hareketinde kendisiyle ayni renkten bir tas var ise dongu kirilir.
				}
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "white")
				{
					chessElements[i].element_point /= 2; //kalenin sag duz hareketinde karsi renkten bir tas var ise o tasin puani yariya iner.
					break;
				}
			} 
			
		}
	}
	else
	{
		for (int i = 0; i < chessElements.size(); ++i)
		{
		
			for (int j = position_y - 1; j > 0; --j)
			{ 
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "white")
				{
					break;
				}
				
				if ( chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "black")
				{
					chessElements[i].element_point /= 2;
					break;
				} 

			
			}
		
			for (int j = position_y + 1; j < 8; ++j)
			{ 
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "white")
				{
					break;
				}
				if (chessElements[i].position_y == j && chessElements[i].position_x == position_x && chessElements[i].element_colour == "black")
				{
					chessElements[i].element_point /= 2;
					break;
				} 
			}

			for (int j = position_x - 1; j > 0; --j)
			{ 
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "white")
				{					
					break;
				}
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "black")
				{
					chessElements[i].element_point /= 2;
					break;
				} 
			} 

			for (int j = position_x + 1; j < 8; ++j)
			{ 
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "white")
				{
					break;
				}
				if (chessElements[i].position_x == j && chessElements[i].position_y == position_y && chessElements[i].element_colour == "black")
				{
					chessElements[i].element_point /= 2;
					break;
				} 
			}  
			
		}
	}
}




