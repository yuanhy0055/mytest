class IFastString
{
public:
	virtual int Length(void) const = 0;				// �����ַ���Ŀ
	virtual int Find(const char *psz) const = 0;	// ����ƫ����

	// ���ٶ���
	//virtual ~IFastString(void) = 0;
	virtual void Delete() = 0;
};
