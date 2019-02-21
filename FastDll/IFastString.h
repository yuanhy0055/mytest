class IFastString
{
public:
	virtual int Length(void) const = 0;				// 返回字符数目
	virtual int Find(const char *psz) const = 0;	// 返回偏移量
};
