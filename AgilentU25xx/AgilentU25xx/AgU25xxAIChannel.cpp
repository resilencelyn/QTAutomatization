#include "AgU25xxAIChannel.h"
#include "AgU25xxException.h"

AgU25xxAIChannel::AgU25xxAIChannel()
    : IAgU25xxSubsystemExtensions()
{
}

AgU25xxAIChannel::AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver)
    : IAgU25xxSubsystemExtensions()
{
    mChannelID = channelName;
    mDriver    = &driver;
}

void AgU25xxAIChannel::setSamplingRate(const unsigned int samplingRate)
{
    QString cmd = mACQuireSubsys.cmdSetSamplingRate(samplingRate);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAIChannel::setEnabled(const bool enabled)
{
    QString cmd = mROUTeSubSys.cmdSetRouteEnabled(enabled, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAIChannel::getEnabled()
{
    QString query       = mROUTeSubSys.cmdGetRouteEnabled(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = extConvertResponseToIntValue(strResponse);

    return intResponse == 1? true : false;
}

void AgU25xxAIChannel::setPolarity(AgU25xxEnumAIChannelPolaities polarity)
{
    QString cmd = mROUTeSubSys.cmdSetAIChannelPolarity(polarity, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelPolaities AgU25xxAIChannel::getPolarity()
{
    QString query       = mROUTeSubSys.cmdGetAIChannelPolarity(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return extGetAIChannelPolarityEnum(strResponse);
}

void AgU25xxAIChannel::setRange(AgU25xxEnumAIChannelRanges range)
{
    QString cmd = mROUTeSubSys.cmdSetAIChannelRange(range, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelRanges AgU25xxAIChannel::getRange()
{
    QString query = mROUTeSubSys.cmdGetAIChannelRange(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return extGetAIChannelRangeEnum(strResponse);
}