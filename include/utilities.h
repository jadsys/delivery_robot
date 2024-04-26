/**
* @file     utilitie.h
* @brief    ユーティリティ関数の定義ヘッダファイル
* @author   S.Kumada
* @date     2023/09/04
* @note     汎用度の高い関数や共通のdefine等の定義
*/

#ifndef UTILITIES_H
#define UTILITIES_H


#include <ros/ros.h>

// rad⇔deg変換
#define deg_to_rad(deg) (((deg)/360)*2*M_PI)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

// ROS Time
#define ROS_NON_RATE                        0.0
#define ROS_RATE_1HZ                        1.0
#define ROS_RATE_10HZ                       10.0
#define ROS_RATE_15HZ                       15.0
#define ROS_RATE_30HZ                       30.0
#define ROS_RATE_45HZ                       45.0
#define ROS_RATE_60HZ                       50.0
#define ROS_RATE_1HZ_TIME                   1/ROS_RATE_1HZ
#define ROS_RATE_10HZ_TIME                  1/ROS_RATE_10HZ
#define ROS_RATE_15HZ_TIME                  1/ROS_RATE_15HZ
#define ROS_RATE_30HZ_TIME                  1/ROS_RATE_30HZ
#define ROS_RATE_45HZ_TIME                  1/ROS_RATE_45HZ
#define ROS_RATE_60HZ_TIME                  1/ROS_RATE_60HZ
#define ROS_TIME_5_SEC                      5
#define ROS_TIME_60_SEC                     60

// queueサイズ
#define ROS_QUEUE_SIZE_1                    1
#define ROS_QUEUE_SIZE_2                    2
#define ROS_QUEUE_SIZE_10                   10

// デフォルトパラメータ
#define DEF_SYSTEM_TYPE                     "ros"
#define DEF_SPACE_INFOMATION                "real"
#define DEF_ROBOT_ID                        "turtlebot_01"
#define DEF_ROBOT_TYPE                      "turtlebot"
#define DEF_MAP_LOCATION                    "lictia_1f"

struct Vector2d
{
    double x;
    double y;

    Vector2d() = default;

    Vector2d(double _x, double _y)
        : x(_x)
        , y(_y) {}

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    double lengthSquare() const
    {
        return x * x + y * y;
    }

    double dot(const Vector2d& other) const
    {
        return x * other.x + y * other.y;
    }

    double distanceFrom(const Vector2d& other) const
    {
        return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
    }

    Vector2d normalized() const
    {
        return{ x / length() , y / length() };
    }

    bool isZero() const
    {
        return x == 0.0 && y == 0.0;
    }

    Vector2d operator +() const
    {
        return *this;
    }

    Vector2d operator -() const
    {
        return{ -x, -y };
    }

    Vector2d operator +(const Vector2d& other) const
    {
        return{ x + other.x, y + other.y };
    }

    Vector2d operator -(const Vector2d& other) const
    {
        return{ x - other.x, y - other.y };
    }

    Vector2d operator *(double s) const
    {
        return{ x * s, y * s };
    }

    Vector2d operator /(double s) const
    {
        return{ x / s, y / s };
    }

    Vector2d& operator +=(const Vector2d& other) // 複合代入演算 +=
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2d& operator -=(const Vector2d& other) // 複合代入演算 -=
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2d& operator *=(double s) // 複合代入演算 *=
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2d& operator /=(double s) // 複合代入演算 /=
    {
        x /= s;
        y /= s;
        return *this;
    }
};

template <typename T>
bool getParam(const ros::NodeHandle &node, const std::string get_key, T &param, T def_param)
{
    bool is_sccess = false;

    if(node.getParam(get_key, param))
    { // 読み込み成功
        ROS_INFO_STREAM("Read success param key: " << get_key.c_str() << " / value: "<< param);
        is_sccess = true;
    }
    else
    { // 読み込み失敗
        ROS_WARN_STREAM("Read failure param key: " << get_key.c_str() << " / value: "<< def_param);
        param = def_param;
    }

    return (is_sccess);
}

std::string rosTimeToIso8601(ros::Time time);

bool strTimeToRosTime(ros::Time &res_time, std::string date_time, std::string format);

std::string iso8601ex(void);

bool checkLastPublishTime(double freq, ros::Time last_pub_time);

#endif