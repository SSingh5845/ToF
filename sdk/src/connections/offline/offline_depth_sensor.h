#ifndef OFFLINE_DEPTH_SENSOR_H
#define OFFLINE_DEPTH_SENSOR_H

#include "aditof/depth_sensor_interface.h"
#include "aditof/sensor_definitions.h"

#include <map>
#include <memory>

class OfflineDepthSensor : public aditof::DepthSensorInterface {
  public:
    OfflineDepthSensor(std::string path);
    ~OfflineDepthSensor();

  public: // implements DepthSensorInterface
    virtual aditof::Status open() override;
    virtual aditof::Status start() override;
    virtual aditof::Status stop() override;
    virtual aditof::Status getAvailableFrameTypes(
        std::vector<aditof::DepthSensorFrameType> &types) override;
    virtual aditof::Status
    setFrameType(const aditof::DepthSensorFrameType &type) override;
    virtual aditof::Status program(const uint8_t *firmware,
                                   size_t size) override;
    virtual aditof::Status getFrame(uint16_t *buffer) override;
    virtual aditof::Status readRegisters(const uint16_t *address,
                                         uint16_t *data, size_t length,
                                         bool burst = true) override;
    virtual aditof::Status writeRegisters(const uint16_t *address,
                                          const uint16_t *data, size_t length,
                                          bool burst = true) override;
    virtual aditof::Status
    getAvailableControls(std::vector<std::string> &controls) const override;
    virtual aditof::Status setControl(const std::string &control,
                                      const std::string &value) override;
    virtual aditof::Status getControl(const std::string &control,
                                      std::string &value) const override;
    virtual aditof::Status
    getDetails(aditof::SensorDetails &details) const override;
    virtual aditof::Status getHandle(void **handle) override;
    virtual aditof::Status getName(std::string &name) const override;
    virtual aditof::Status
    setHostConnectionType(std::string &connectionType) override;

    virtual aditof::Status adsd3500_read_cmd(uint16_t cmd, uint16_t *data,
                                             unsigned int usDelay) override;
    virtual aditof::Status adsd3500_write_cmd(uint16_t cmd,
                                              uint16_t data) override;
    virtual aditof::Status
    adsd3500_read_payload_cmd(uint32_t cmd, uint8_t *readback_data,
                              uint16_t payload_len) override;
    virtual aditof::Status adsd3500_read_payload(uint8_t *payload,
                                                 uint16_t payload_len) override;
    virtual aditof::Status
    adsd3500_write_payload_cmd(uint32_t cmd, uint8_t *payload,
                               uint16_t payload_len) override;
    virtual aditof::Status
    adsd3500_write_payload(uint8_t *payload, uint16_t payload_len) override;
    virtual aditof::Status adsd3500_register_interrupt_callback(
        aditof::SensorInterruptCallback &cb) override;
    virtual aditof::Status adsd3500_unregister_interrupt_callback(
        aditof::SensorInterruptCallback &cb) override;
    virtual aditof::Status adsd3500_reset() override;
    virtual aditof::Status adsd3500_get_status(int &chipStatus,
                                               int &imagerStatus) override;
    virtual aditof::Status
    initTargetDepthCompute(uint8_t *iniFile, uint16_t iniFileLength,
                           uint8_t *calData, uint16_t calDataLength) override;

  private:
    std::string m_connectionType;
    aditof::SensorDetails m_sensorDetails;
    std::vector<aditof::DepthSensorFrameType> m_depthSensorFrameTypes;
    std::string m_path;
    std::string m_frameTypeSelected;
    std::map<std::string, std::pair<std::uint16_t *, std::size_t>> m_frameTypes;
    const std::vector<aditof::DepthSensorFrameType> availableFrameTypes = {
        {
            "sr-native",
            {{"raw", 1024, 4096},
             {"depth", 1024, 1024},
             {"ab", 1024, 1024},
             {"conf", 1024, 1024},
             {"xyz", 1024, 1024},
             {"metadata", 1, 128}},
            1024,
            4096,
        },
        {
            "lr-native",
            {{"raw", 1024, 4096},
             {"depth", 1024, 1024},
             {"ab", 1024, 1024},
             {"conf", 1024, 1024},
             {"xyz", 1024, 1024},
             {"metadata", 1, 128}},
            1024,
            4096,
        },
        {
            "sr-qnative",
            {{"raw", 2560, 512},
             {"depth", 512, 512},
             {"ab", 512, 512},
             {"conf", 512, 512},
             {"xyz", 512, 512},
             {"metadata", 1, 128}},
            2560,
            512,
        },
        {
            "lr-qnative",
            {{"raw", 2560, 512},
             {"depth", 512, 512},
             {"ab", 512, 512},
             {"conf", 512, 512},
             {"xyz", 512, 512},
             {"metadata", 1, 128}},
            2560,
            512,
        },
        {
            "sr-mixed",
            {{"raw", 2560, 512},
             {"depth", 512, 512},
             {"ab", 512, 512},
             {"conf", 512, 512},
             {"xyz", 512, 512},
             {"metadata", 1, 128}},
            2560,
            512,
        },
        {
            "lr-mixed",
            {{"raw", 2560, 512},
             {"depth", 512, 512},
             {"ab", 512, 512},
             {"conf", 512, 512},
             {"xyz", 512, 512},
             {"metadata", 1, 128}},
            2560,
            512,
        }};
};

#endif // OFFLINE_DEPTH_SENSOR_H
