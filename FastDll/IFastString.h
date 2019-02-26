class IFastString
{
public:
	virtual int Length(void) const = 0;				// 返回字符数目
	virtual int Find(const char *psz) const = 0;	// 返回偏移量

	// 销毁对象
	//virtual ~IFastString(void) = 0;
	virtual void Delete() = 0;
};
