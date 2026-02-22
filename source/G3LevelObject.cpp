#include "G3LevelObject.h"

std::shared_ptr<G3LevelObject> G3LevelObject::create()
{
    return std::make_shared<G3LevelObject>();
}

void G3LevelObject::setupObject(std::string_view objectString)
{
    constexpr std::string_view delim{","};
    int propKey{};
    int propCount{0};

    for (const auto prop : std::views::split(objectString, delim))
    {
        auto str = std::string_view(prop);
        if (!(propCount % 2))
        {
            propKey = std::atoi(str.data());
            ++propCount;
            continue;
        }

        switch (propKey)
        {
        case 1:
            m_objectID = std::atoi(str.data());
            break;
        case 2:
            m_posX = (std::atof(str.data()));
            break;
        case 3:
            m_posY = (-(std::atof(str.data()))) + G3Consts::screenHeight;
            break;
        case 4:
            m_flipH = std::atoi(str.data());
            break;
        case 5:
            m_flipV = std::atoi(str.data());
            break;
        case 6:
            m_rotDegree = std::atof(str.data());
            break;
        }
        ++propCount;
    }

    int spriteID{getSpriteID(m_objectID)};

    if (spriteID == -1)
    {
        m_shouldDraw = false;
    }
    else
    {
        setSprite(G3Sheets::objects, spriteID);
    };
}

int G3LevelObject::getSpriteID(int objectID)
{
    int sprID{-1};

    switch (objectID)
    {
    case 1:
        sprID = objects_square_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 2:
        sprID = objects_square_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 3:
        sprID = objects_square_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 4:
        sprID = objects_square_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 5:
        sprID = objects_square_05_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 6:
        sprID = objects_square_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 7:
        sprID = objects_square_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 8:
        sprID = objects_spike_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 9:
        sprID = objects_pit_01_001_idx + G3Random::get(0, 2);
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 10:
        sprID = objects_portal_01_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 11:
        sprID = objects_portal_02_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 12:
        sprID = objects_portal_03_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 13:
        sprID = objects_portal_04_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    // NO 14
    case 15:
        sprID = objects_rod_01_001_idx;
        m_zLayer = -2;
        m_zOrder = -6;
        break;
    case 16:
        sprID = objects_rod_02_001_idx;
        m_zLayer = -2;
        m_zOrder = -6;
        break;
    case 17:
        sprID = objects_rod_03_001_idx;
        m_zLayer = -2;
        m_zOrder = -6;
        break;
    case 18:
        sprID = objects_d_spikes_01_001_idx;
        m_zLayer = -1;
        m_zOrder = -9;
        break;
    case 19:
        sprID = objects_d_spikes_02_001_idx;
        m_zLayer = -1;
        m_zOrder = -9;
        break;
    case 20:
        sprID = objects_d_spikes_03_001_idx;
        m_zLayer = -1;
        m_zOrder = -9;
        break;
    case 21:
        sprID = objects_d_spikes_04_001_idx;
        m_zLayer = -1;
        m_zOrder = -9;
        break;
    // 22 - 34 ALL TRIGGERS (might need to make a case for all of em later)
    case 35:
        sprID = objects_bump_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    case 36:
        sprID = objects_ring_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    // NO 37 - 38
    case 39:
        sprID = objects_spike_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 40:
        sprID = objects_plank_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 41:
        sprID = objects_chain_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    // NO 42 - 44
    case 45:
        sprID = objects_portal_05_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 46:
        sprID = objects_portal_06_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 47:
        sprID = objects_portal_07_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    case 48:
        sprID = objects_d_cloud_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 49:
        sprID = objects_d_cloud_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 50:
        sprID = objects_d_ball_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 51:
        sprID = objects_d_ball_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 52:
        sprID = objects_d_ball_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 53:
        sprID = objects_d_ball_04_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 54:
        sprID = objects_d_ball_05_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    // 55 - 59 trigger
    case 60:
        sprID = objects_d_ball_06_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 61:
        sprID = objects_pit_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 62:
        sprID = objects_square_b_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 63:
        sprID = objects_square_b_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 64:
        sprID = objects_square_b_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 65:
        sprID = objects_square_b_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 66:
        sprID = objects_square_b_05_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 67:
        sprID = objects_gravbump_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    case 68:
        sprID = objects_square_b_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 69:
        sprID = objects_square_c_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 70:
        sprID = objects_square_c_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 71:
        sprID = objects_square_c_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 72:
        sprID = objects_square_c_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 73:
        sprID = objects_square_c_05_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 74:
        sprID = objects_square_c_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 75:
        sprID = objects_square_c_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 76:
        sprID = objects_square_d_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 77:
        sprID = objects_square_d_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 78:
        sprID = objects_square_d_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    // no 79....
    case 80:
        sprID = objects_square_d_05_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 81:
        sprID = objects_square_d_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 82:
        sprID = objects_square_d_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 83:
        sprID = objects_square_08_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 84:
        sprID = objects_gravring_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    case 85:
        sprID = objects_d_cogwheel_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 86:
        sprID = objects_d_cogwheel_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 87:
        sprID = objects_d_cogwheel_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 88:
        sprID = objects_sawblade_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 89:
        sprID = objects_sawblade_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 90:
        sprID = objects_square_e_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 91:
        sprID = objects_square_e_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 92:
        sprID = objects_square_e_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 93:
        sprID = objects_square_e_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 94:
        sprID = objects_square_e_05_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 95:
        sprID = objects_square_e_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 96:
        sprID = objects_square_e_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 97:
        sprID = objects_d_cogwheel_04_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 98:
        sprID = objects_sawblade_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 99:
        sprID = objects_portal_08_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    // NO 100
    case 101:
        sprID = objects_portal_09_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    // NO 102
    case 103:
        sprID = objects_spike_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    // 104-105 TRIGGERS((!!))
    case 106:
        sprID = objects_d_02_chain_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 107:
        sprID = objects_d_02_chain_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    // NO 108-109
    case 110:
        sprID = objects_d_chain_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 111:
        sprID = objects_portal_10_front_001_idx;
        m_zLayer = 1;
        m_zOrder = 10;
        break;
    // NO 112
    case 113:
        sprID = objects_d_brick_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 114:
        sprID = objects_d_brick_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 115:
        sprID = objects_d_brick_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 116:
        sprID = objects_square_f_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 117:
        sprID = objects_square_f_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 118:
        sprID = objects_square_f_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 119:
        sprID = objects_square_f_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 120:
        sprID = objects_square_f_05_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 121:
        sprID = objects_square_f_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 122:
        sprID = objects_square_f_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 123:
        sprID = objects_d_thorn_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 124:
        sprID = objects_d_thorn_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 125:
        sprID = objects_d_thorn_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 126:
        sprID = objects_d_thorn_04_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 127:
        sprID = objects_d_thorn_05_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 128:
        sprID = objects_d_thorn_06_001_idx;
        m_zLayer = -1;
        m_zOrder = 1;
        break;
    case 129:
        sprID = objects_d_cloud_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 130:
        sprID = objects_d_cloud_04_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 131:
        sprID = objects_d_cloud_05_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 132:
        sprID = objects_d_arrow_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 10;
        break;
    case 133:
        sprID = objects_d_exmark_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 10;
        break;
    case 134:
        sprID = objects_d_art_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 135:
        sprID = objects_pit_b_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 136:
        sprID = objects_d_qmark_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 10;
        break;
    case 137:
        sprID = objects_d_wheel_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 138:
        sprID = objects_d_wheel_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 139:
        sprID = objects_d_wheel_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 140:
        sprID = objects_bump_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    case 141:
        sprID = objects_ring_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 12;
        break;
    // no 142
    case 143:
        sprID = objects_brick_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 144:
        sprID = objects_invis_spike_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 145:
        sprID = objects_invis_spike_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 146:
        sprID = objects_invis_square_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 147:
        sprID = objects_invis_plank_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 148:
        sprID = objects_d_ball_07_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 149:
        sprID = objects_d_ball_08_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 150:
        sprID = objects_d_cross_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 10;
        break;
    case 151:
        sprID = objects_d_spikeart_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 152:
        sprID = objects_d_spikeart_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 153:
        sprID = objects_d_spikeart_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 154:
        sprID = objects_d_spikewheel_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 155:
        sprID = objects_d_spikewheel_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 156:
        sprID = objects_d_spikewheel_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 157:
        sprID = objects_d_wave_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 158:
        sprID = objects_d_wave_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 159:
        sprID = objects_d_wave_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 160:
        sprID = objects_square_g_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 161:
        sprID = objects_square_g_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 162:
        sprID = objects_square_g_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 163:
        sprID = objects_square_g_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 164:
        sprID = objects_square_g_05_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 165:
        sprID = objects_square_g_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 166:
        sprID = objects_square_g_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 167:
        sprID = objects_square_g_08_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 168:
        sprID = objects_square_g_09_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 169:
        sprID = objects_square_g_10_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 170:
        sprID = objects_square_h_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 171:
        sprID = objects_square_h_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 172:
        sprID = objects_square_h_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 173:
        sprID = objects_square_h_04_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 174:
        sprID = objects_square_h_05_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 175:
        sprID = objects_square_h_06_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 176:
        sprID = objects_square_h_07_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 177:
        sprID = objects_iceSpike_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 178:
        sprID = objects_iceSpike_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 179:
        sprID = objects_iceSpike_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 180:
        sprID = objects_d_cartwheel_01_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 181:
        sprID = objects_d_cartwheel_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 182:
        sprID = objects_d_cartwheel_03_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 183:
        sprID = objects_blade_b_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 184:
        sprID = objects_blade_b_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 185:
        sprID = objects_blade_b_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 186:
        sprID = objects_blade_01_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 187:
        sprID = objects_blade_02_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    case 188:
        sprID = objects_blade_03_001_idx;
        m_zLayer = 1;
        m_zOrder = 1;
        break;
    // no 189
    case 190:
        sprID = objects_d_art_02_001_idx;
        m_zLayer = -1;
        m_zOrder = 9;
        break;
    case 191:
        sprID = objects_fakeSpike_01_001_idx;
        m_zLayer = -2;
        m_zOrder = -4;
        break;
    case 192:
        sprID = objects_square_h_08_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 193:
        sprID = objects_square_g_11_001_idx;
        m_zLayer = -2;
        m_zOrder = -7;
        break;
    case 194:
        sprID = objects_square_h_09_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 195:
        sprID = objects_square_01_small_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    case 196:
        sprID = objects_plank_01_small_001_idx;
        m_zLayer = 1;
        m_zOrder = 2;
        break;
    // no 197
    case 198:
        sprID = objects_fakeSpike_02_001_idx;
        m_zLayer = -2;
        m_zOrder = -4;
        break;
    case 199:
        sprID = objects_fakeSpike_03_001_idx;
        m_zLayer = -2;
        m_zOrder = -4;
        break;
    }

    return sprID;
}

void G3LevelObject::draw()
{
    if (m_shouldDraw)
        G3Sprite::draw();
}

int G3LevelObject::getZLayer()
{
    return m_zLayer;
}
