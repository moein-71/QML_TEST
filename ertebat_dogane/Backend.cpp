#include "Backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
{
}

QString Backend::outputText() const
{
    return m_outputText;
}

void Backend::updateText(const QString &input)
{
    m_outputText = input.toUpper(); 
    emit outputTextChanged();   
}
