export function friend_request_response(public_key) {
    window.ws.current.send(JSON.stringify({
                "event_id" : 0,
                "event_type" : "request_accept",
                "event_body" : {
                    "public_key" : public_key
                }
    }))
}
export const dark_theme_style_container = {
        backgroundColor:"rgb(30, 30, 30)",
        color: 'white'
    }
export const avatar_size = { xs: 30, sm: 35, md: 40, lg: 45, xl: 45, xxl: 55 }
const formatter_obj = new Intl.DateTimeFormat('en-GB', {
  year: 'numeric', month: '2-digit', day: '2-digit',
  hour: 'numeric', minute: '2-digit', second: '2-digit',
  hourCycle: 'h12',
});

export const formatter = (iso_date) => {
    console.log(iso_date)
    try {
        return formatter_obj.format(new Date(iso_date))
    } catch (e) {
        return 'NA'
    }

}

