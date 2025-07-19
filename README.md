# 🔌Power Monitoring Device using IoT ⚡

## 📌 Project Overview
This project focuses on designing and implementing a cost-effective **IoT-based Power Monitoring Device** that allows real-time energy tracking of household appliances. By providing **appliance-wise monitoring**, this device empowers users to optimize energy consumption, reduce power bills, and promote sustainability. Data is displayed on a **mobile/web dashboard** with real-time updates and historical analytics.

---

## 📝 Abstract
Energy consumption is integral to modern living, but many households lack effective tools to monitor their usage. This project aims to solve this by creating an affordable **IoT-based Power Monitoring Device**. It offers:
- Real-time energy tracking
- Appliance-specific consumption data
- Mobile-based remote monitoring
- Alerts for unusual power usage

The goal is to provide users with actionable data to improve energy efficiency and contribute to sustainability.

---

## ⚙️ Components Used
| Component                          | Description                          |
|-------------------------------------|---------------------------------------|
| **ESP32 Wroom**                     | Main microcontroller with Wi-Fi       |
| **Current Sensor (SCT013)**         | Measures current flow                |
| **Voltage Sensor (ZMPT101B)**       | Measures voltage                     |
| **Capacitors (10μF)**               | Circuit stability                    |
| **Resistors (10kΩ, 100Ω)**          | Voltage division and biasing         |
| **PCB and Wiring**                  | For stable connections               |

---

## 🚀 Methodology

<img width="918" height="837" alt="image" src="https://github.com/user-attachments/assets/750cc1df-f7fd-4601-9c35-c55d6cf2b367" />


### 1. Data Acquisition
- Voltage and Current sensors (ZMPT101B & SCT013) measure real-time power flow.

### 2. Data Processing
- ESP32 microcontroller processes the inputs and calculates:
  - Voltage (Vrms)
  - Current (Irms)
  - Power Consumption (P = Vrms × Irms × PF)

### 3. Data Display & Transmission
- Real-time data is shown on an LCD/OLED screen.
- Data is transmitted via **Wi-Fi** using **MQTT/HTTP** protocols.

### 4. Cloud & App Integration
- Data is sent to **Blynk App** or cloud dashboards for visualization and historical tracking.

### 5. Alerts & Notifications
- Users receive alerts on abnormal energy spikes or faults via mobile notifications.

---

## 🛠️ Construction Details
- **Voltage Sensor (ZMPT101B)** → Connected to ESP32 ADC pin (e.g., GPIO36).
- **Current Sensor (SCT013)** → Connected to ESP32 ADC pin (e.g., GPIO34).
- ESP32 powered using 5V supply with proper grounding.
- **Arduino IDE** used for programming with libraries:
  - `EmonLib.h` for power calculation
  - `BlynkSimpleEsp32.h` for mobile app connectivity
  - `WiFiClient.h` for internet connectivity

---

## 🏗️ Working Principle
- Sensors measure **current** and **voltage** from appliances.
- ESP32 calculates **real power** and sends it to a **mobile app** via Wi-Fi.
- The app displays **real-time energy usage**, **historical consumption trends**, and provides **alerts**.
- Enables **appliance-wise monitoring** and helps in **decision-making** for energy conservation.

---

## 📊 Comparative Study

| **Parameter**               | **Traditional Meters** | **IoT Power Monitoring Device** |
|-----------------------------|------------------------|---------------------------------|
| Real-Time Monitoring        | ❌ No                  | ✅ Yes                          |
| Appliance-Specific Data     | ❌ No                  | ✅ Yes                          |
| Remote Access               | ❌ No                  | ✅ Yes                          |
| Data Analytics              | ❌ No                  | ✅ Yes                          |

---

## 🌍 Social Impact
- Promotes **energy conservation** and **responsible consumption**.
- Helps reduce **financial burdens** by lowering electricity bills.
- Supports transition to **smart homes** and **energy-efficient lifestyles**.
- Contributes towards **UN Sustainable Development Goal (SDG 7)**: Affordable and clean energy.

---

## ✨ Salient Features
- Real-time energy monitoring with **mobile/web interface**.
- **Appliance-specific consumption tracking**.
- **Wi-Fi enabled**, easy to integrate into smart homes.
- **Alert notifications** for unusual energy usage.
- Helps reduce **unnecessary consumption** and electricity costs.

---

## Circuit Diagram 
<img width="1364" height="701" alt="image" src="https://github.com/user-attachments/assets/ed8eb933-9d61-412f-a7bf-3cf3f2f2744c" />

## Prototype Image

<img width="885" height="450" alt="image" src="https://github.com/user-attachments/assets/ae2946f5-36e9-487e-8d1b-0c93bf5661b6" />

<img width="871" height="498" alt="image" src="https://github.com/user-attachments/assets/8515e810-0fcf-416a-a752-c55fc67a34ff" />



---
## 💡 Business Plan
**Target Market**: Households, educational institutions, small commercial spaces.

**Revenue Model**:
- Direct device sales
- Premium app features (advanced analytics)
- Collaborations with power utilities for smart grid initiatives

**Future Expansion**:
- AI-based **energy-saving recommendations**
- Integration with **home automation**
- Expansion to **industrial energy monitoring**

---

## 💸 Project Cost Breakdown

| Component                      | Cost (INR) |
|--------------------------------|------------|
| ESP32 Wroom                     | ₹500       |
| Current Sensor (SCT013)         | ₹600       |
| Voltage Sensor (ZMPT101B)       | ₹600       |
| PCB and Wiring                  | ₹200       |
| Capacitors & Resistors          | ₹100       |
| Software                        | ₹500       |
| Manpower                        | ₹500       |
| **Total Cost**                  | **₹3000**  |

---

## 🎁 Expected Outcomes
- Affordable, **real-time energy monitoring** solution.
- Increased **awareness of energy habits**.
- Reduction in **electricity bills**.
- Contribution towards **sustainability**.

---

## ✅ Conclusion
The **IoT-based Power Monitoring Device** provides a **smart, cost-effective, and efficient solution** for tracking household electricity consumption. It empowers users with **real-time insights**, promotes **energy saving**, and supports **smart home ecosystems**. This project not only addresses everyday energy efficiency challenges but also aligns with broader sustainability goals.

---





