class IFastString
{
public:
	virtual int Length(void) const = 0;				// �����ַ���Ŀ
	virtual int Find(const char *psz) const = 0;	// ����ƫ����
};
