#ifndef QTMATERIALCIRCULARPROGRESS_H
#define QTMATERIALCIRCULARPROGRESS_H

#include <QtWidgets/QProgressBar>
#include "lib/qtmaterialtheme.h"
#include "qtmaterial_global.h"

class QtMaterialCircularProgressPrivate;

class QT_MATERIAL_EXPORT QtMaterialCircularProgress : public QProgressBar
{
    Q_OBJECT

    Q_PROPERTY(MaterialConst::ProgressType progressType WRITE setProgressType READ progressType)
    Q_PROPERTY(bool useThemeColors WRITE setUseThemeColors READ useThemeColors)
    Q_PROPERTY(qreal lineWidth WRITE setLineWidth READ lineWidth)
    Q_PROPERTY(qreal size WRITE setSize READ size)
    Q_PROPERTY(QColor color WRITE setColor READ color)

public:
    explicit QtMaterialCircularProgress(QWidget *parent = 0);
    ~QtMaterialCircularProgress();

    void setProgressType(MaterialConst::ProgressType type);
    MaterialConst::ProgressType progressType() const;

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setLineWidth(qreal width);
    qreal lineWidth() const;

    void setSize(int size);
    int size() const;

    void setColor(const QColor &color);
    QColor color() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const QScopedPointer<QtMaterialCircularProgressPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QtMaterialCircularProgress)
    Q_DECLARE_PRIVATE(QtMaterialCircularProgress)
};

#endif // QTMATERIALCIRCULARPROGRESS_H
