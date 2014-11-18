
typedef struct parameters_type
{
	float temperature_;
	float humidity_;
	unsigned char active_;
} parameters;

extern int setTemp( parameters * const this, const float );
extern int getTemp( parameters * const this, float * temp); const
extern int setHumi( parameters * const this, const float humi);
extern int getHumi( parameters * const this, float * humia); const
extern int setActive( parameters * const this, const unsigned char);
extern int getActive( parameters * const this, unsigned char *); const