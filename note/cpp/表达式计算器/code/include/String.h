#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
    explicit String(const char *str = "");
    // 提供一个拷贝构造函数，实现深拷贝
    String(const String &other);
    String &operator=(const String &other);
    String &operator=(const char *str);

    bool operator!() const;

    ~String(void);

    void Display() const;

private:
    char *AllocAndCpy(const char *str);
    char *str_;
};

#endif // !_STING_H_