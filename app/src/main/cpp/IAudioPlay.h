//
// Created by pengt on 2018/10/26.
//

#ifndef MYXPLAY_IAUDIOPLAY_H
#define MYXPLAY_IAUDIOPLAY_H


#include <list>
#include "IObserver.h"
#include "XParameter.h"

class IAudioPlay : public IObserver{
public:
    //缓冲满后阻塞
    virtual void Update(XData data);

    //获取缓冲数据，如没有则阻塞
    virtual XData GetData();

    virtual bool StartPlay(XParameter out) = 0;
    //最大缓冲
    int maxFrame = 100;
protected:
    std::list<XData> frames;
    std::mutex framesMutex;
};


#endif //MYXPLAY_IAUDIOPLAY_H
