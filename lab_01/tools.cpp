#include <QString>

/**
 * \brief Convert QString to const char *
 * 
 * \param str
 * \return 
 */
const char *ConvertQString(QString str)
{
    QByteArray b_str = str.toLocal8Bit();
    const char* c_str2 = b_str.data();
    return c_str2;
}