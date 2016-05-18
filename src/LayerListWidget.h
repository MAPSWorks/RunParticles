#ifndef LAYERLISTWIDGET_H
#define LAYERLISTWIDGET_H

#include <QAction>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "Layer.h"

class LayerListWidgetItem : public QTreeWidgetItem
{
public:
    LayerListWidgetItem(QTreeWidget *tree) : QTreeWidgetItem(tree)  {}
    LayerListWidgetItem(QTreeWidget * parent, const QStringList & strings)
        : QTreeWidgetItem (parent,strings)  {}
    void setData(int column, int role, const QVariant & value);
    
    bool operator<(const QTreeWidgetItem & other) const;
};

class LayerListWidget : public QTreeWidget
{
    
    Q_OBJECT
    
public:
    
    enum LayerListColumns
    {
        ColumnVisible,
        ColumnName,
        ColumnSport,
        ColumnStartTime,
        ColumnDuration,
        ColumnCount
    };
    
    enum LayerListRoles
    {
        LayerIdRole = Qt::UserRole,
        NumericRole,
        DateTimeRole
    };
    
    LayerListWidget(QWidget *parent=0);
    ~LayerListWidget();
    void addLayer(Layer *layer);
    void removeLayers(const QList<LayerId> &layerIds);
    QList<LayerId> selectedLayerIds() const;
    
    void itemChecked(LayerListWidgetItem *which, int column);
    
signals:
    void signalLayerSelectionChanged(QList<LayerId>);
    void signalFrameLayers(QList<LayerId>);
    void signalLayerVisibilityChanged(LayerId, bool);
    void signalLockViewToLayer(LayerId);
    void signalRemoveLayersSelected(QList<LayerId>);
    
public slots:
    void slotSetSelectedLayers(QList<LayerId> layerIds);
    
protected slots:
    void onSelectionChanged();
    void onFrameLayersSelected();
    void onLockViewSelected();
    void onShowLayersSelected();
    void onHideLayersSelected();
    void onRemoveLayersSelected();
    
protected:
    QAction *_frameLayerAction;
    QAction *_lockViewAction;
    QAction *_showLayersAction;
    QAction *_hideLayersAction;
    QAction *_removeLayersAction;
    bool _inLayerAdd;
};

#endif
