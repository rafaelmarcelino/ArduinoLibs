//Definição das funcionalidades da classe ToolsGeneral

#include "AnimationRGBW.h"

//Construtor
AnimationRGBW::AnimationRGBW() {}

//Funcionalidade da função getDinamycRangeOfColor
byte AnimationRGBW::getDinamycRangeOfBrigh(long maxSeconds, long actualSeconds, byte maxValueForThisColor)
{
    //Proteção contra valores altos para a cores
    byte _maxValueForThisColor = maxValueForThisColor;
    if (_maxValueForThisColor > 255)
    {
        _maxValueForThisColor = 255;
    }
    else if (_maxValueForThisColor < 0)
    {
        _maxValueForThisColor = 0;
    }

    //Funcionalidade do método
    //Verifica se não existe divisão por 0 para não retornar um valor equívocado
    if ((maxSeconds == 0) ||
        (_maxValueForThisColor == 0) ||
        (((actualSeconds * _maxValueForThisColor) / maxSeconds) > 255))
    {
        return 0;
    }
    else
    {
        return ((actualSeconds * _maxValueForThisColor) / maxSeconds);
    }
}
//Funcionalidade da função pulseColor
byte AnimationRGBW::pulseColor(long maxSeconds, long actualSeconds, byte maxValueForThisColor)
{
    byte _returnValue = 0;
    //Proteção contra valores altos para a cores
    byte _maxValueForThisColor = maxValueForThisColor;
    if (_maxValueForThisColor > 255)
    {
        _maxValueForThisColor = 255;
    }
    else if (_maxValueForThisColor < 0)
    {
        _maxValueForThisColor = 0;
    }

    //Funcionalidade do método
    //Verifica valor da memória para definir incremento ou decremento do brilho
    if (_memActualSecondsPC > actualSeconds)
    {
        _invertDirectionPC = !_invertDirectionPC;
    }

    //Verifica se não existe divisão por 0 para não retornar um valor equívocado
    if ((maxSeconds == 0) ||
        (_maxValueForThisColor == 0))
    {
        return 0;
    }
    else
    {
        //Caso não esteja setado inversão de brilho, incrementa o valor
        if (!_invertDirectionPC)
        {
            _returnValue = ((actualSeconds * _maxValueForThisColor) / maxSeconds);
        }
        //Caso contrário, decrementa o valor        
        else
        {
            _returnValue = (_maxValueForThisColor - ((actualSeconds * _maxValueForThisColor) / maxSeconds));
        }
    }
    //Atualiza memória de segundos, para determinar incremento e decremento
    _memActualSecondsPC = actualSeconds;

    return _returnValue;
}
//Funcionalidade da função incrementPixelByTime
byte AnimationRGBW::incrementPixelByTime(long maxSeconds, long actualSeconds, byte maxNumberOfPixels)
{
    //Proteção contra valores altos para a cores
    byte _maxNumberOfPixels = maxNumberOfPixels;
    if (_maxNumberOfPixels > 255)
    {
        _maxNumberOfPixels = 255;
    }
    else if (_maxNumberOfPixels < 0)
    {
        _maxNumberOfPixels = 0;
    }

    //Funcionalidade do método
    //Verifica se não existe divisão por 0 para não retornar um valor equívocado
    if ((maxSeconds == 0) ||
        (_maxNumberOfPixels == 0) ||
        (((actualSeconds * _maxNumberOfPixels) / maxSeconds) > _maxNumberOfPixels))
    {
        return 0;
    }
    else
    {
        return ((actualSeconds * _maxNumberOfPixels) / maxSeconds);
    }
}
