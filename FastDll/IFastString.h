class IFastString
{
public:
	virtual int Length(void) const = 0;				// �����ַ���Ŀ
	virtual int Find(const char *psz) const = 0;	// ����ƫ����
	virtual int FindN(const char *psz, int n) const = 0;	// �����·���

	// ���ٶ���
	//virtual ~IFastString(void) = 0;
	virtual void Delete() = 0;
};
