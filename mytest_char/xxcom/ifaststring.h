// ifaststring.h �ӿ���
class IFastString
{
public:
	virtual int Length(void) const = 0;
	virtual int Find(const char* psz) = 0;
};