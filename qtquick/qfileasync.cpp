/*
 * Copyright 2013 KanMemo Project.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "qfileasync.h"
#include <QDebug>
#include <QFile>

QFileAsync::QFileAsync(QObject *parent) :
    QThread(parent)
{
}


void QFileAsync::run()
{
    bool ret = false;

    qDebug() << "run file ope.";

    switch(m_Operation){
    case Copy:
        ret = QFile::copy(m_fileName, m_newName);
        break;

    case Move:
        ret = QFile::copy(m_fileName, m_newName);
        if(ret){
            ret = QFile::remove(m_fileName);
        }
        break;

    case Delete:
        ret = QFile::remove(m_fileName);
        break;

    default:
        break;
    }

    emit finished(ret);
}