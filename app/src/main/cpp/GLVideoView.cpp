//
// Created by pengt on 2018/10/24.
//

#include "GLVideoView.h"
#include "XTexture.h"

void GLVideoView::SetRender(void *win) {
    view = win;
}

void GLVideoView::Render(XData data) {
    if(!view){
        return;
    }
    if(!txt){
        txt = XTexture::Create();
        txt->Init(view,(XTextureType)data.format);
    }
    txt->Draw(data.datas,data.width,data.height);
}