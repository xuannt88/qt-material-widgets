#ifndef QTMATERIALSLIDER_H
#define QTMATERIALSLIDER_H

#include <QtWidgets/QAbstractSlider>
#include <QScopedPointer>
#include "qtmaterial_global.h"

#define QT_MATERIAL_SLIDER_MARGIN 10

class QtMaterialSliderPrivate;

class QT_MATERIAL_EXPORT QtMaterialSlider : public QAbstractSlider
{
    Q_OBJECT

    Q_PROPERTY(bool useThemeColors WRITE setUseThemeColors READ useThemeColors)
    Q_PROPERTY(QColor thumbColor WRITE setThumbColor READ thumbColor)
    Q_PROPERTY(QColor trackColor WRITE setTrackColor READ trackColor)
    Q_PROPERTY(QColor disabledColor WRITE setDisabledColor READ disabledColor)
    Q_PROPERTY(bool pageStepMode WRITE setPageStepMode READ pageStepMode)
    Q_PROPERTY(bool invertedAppearance WRITE setInvertedAppearance)

public:
    explicit QtMaterialSlider(QWidget *parent = 0);
    ~QtMaterialSlider();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setThumbColor(const QColor &color);
    QColor thumbColor() const;

    void setTrackColor(const QColor &color);
    QColor trackColor() const;

    void setDisabledColor(const QColor &color);
    QColor disabledColor() const;

    void setPageStepMode(bool pageStep);
    bool pageStepMode() const;

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

    void setInvertedAppearance(bool value);

protected:
    void sliderChange(SliderChange change) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;

    void updateThumbOffset();

    const QScopedPointer<QtMaterialSliderPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QtMaterialSlider)
    Q_DECLARE_PRIVATE(QtMaterialSlider)
};

#endif // QTMATERIALSLIDER_H
