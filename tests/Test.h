#include "base/Base.h"

class ConditonException
{
public:
	ConditonException(const std::string& message,
		const std::string& file,int line)
	{
		this->message = message;
		this->file = file;
		this->line = line;
	}

	void printErrorMsg()
	{
		printf("%s file: %s,line:%d\n",message.c_str(),file.c_str(),line);
	}
private:
	std::string message;
	int line;
	std::string file;
};

#define INTERNAL_EXPECT_EQ(x,y,file,line)		{					\
								if((x) != (y))						\
								{									\
									std::string strfile = file;		\
									std::string msg = "check EXPECT_EQ(";	\
									msg += #x;						\
									msg += ",";						\
									msg += #y;						\
									msg += ") failed!";				\
									throw ConditonException(msg,strfile,line); \
								}											\
							}

#define EXPECT_EQ(x,y) INTERNAL_EXPECT_EQ(x,y,__FILE__,__LINE__)

#define INTERNAL_EXPECT_TRUE(cond,file,line)		{	\
	if(!(cond))						\
{									\
	std::string strfile = file;		\
	std::string msg = "check EXPECT_TRUE(";	\
	msg += #cond;						\
	msg += ") failed!";					\
	throw ConditonException(msg,strfile,line); \
}											\
}

#define EXPECT_TRUE(cond) INTERNAL_EXPECT_TRUE(cond,__FILE__,__LINE__)

#define INTERNAL_EXPECT_FALSE(cond,file,line)		{	\
	if(cond)						\
{									\
	std::string strfile = file;		\
	std::string msg = "check EXPECT_FALSE(";	\
	msg += #cond;						\
	msg += ") failed!";					\
	throw ConditonException(msg,strfile,line); \
}											\
}

#define EXPECT_FALSE(cond) INTERNAL_EXPECT_FALSE(cond,__FILE__,__LINE__)


typedef void (*TestFun)(void);
 
std::map<TestFun,std::string> allFuns;

#define TEST(fun) 			\
	void fun##_test(void); 	\
							\
	class fun##_class{		\
	public:					\
		fun##_class()		\
		{					\
			allFuns.insert(std::pair<TestFun,std::string>(fun##_test,#fun));	\
		}					\
	};						\
							\
	static fun##_class fun##obj;	\
							\
	void fun##_test(void)	
	
void main()
{
	printf("===========start do tests============\n");
	std::map<TestFun,std::string>::iterator it = allFuns.begin();
	for(;it != allFuns.end();it++)
	{
		printf("-----------%s begin-----------\n",it->second.c_str());
		try
		{
			it->first();
		}
		catch(ConditonException& e)
		{
			printf("-----------%s failed-----------\n",it->second.c_str());
			e.printErrorMsg();
			exit(1);
		}
		printf("-----------%s pass-----------\n",it->second.c_str());
	}
	printf("===========end do tests============\n");
}